// 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define SIZE 100
#define MAX_TEXT 100
typedef struct
{
char items[SIZE][MAX_TEXT];
int top;
} Stack;
void initstack(Stack *s)
{
s->top = -1;
}
int isfull(Stack *s)
{
return s->top == SIZE - 1;
}
int isempty(Stack *s)
{
return s->top == -1;
}
void push(Stack *s, const char *text)
{
if (isfull(s))
{
printf("Stack is full\n");
return;
}
strcpy(s->items[++(s->top)], text);
}
int *pop(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return ;
}
return s->items[(s->top)--];
}
int peek(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return -1;
}
return s->items[s->top];
}
int main()
{
Stack undoStack, redoStack;
char currentText[MAX_TEXT] = "";
char input[MAX_TEXT];
int choice;
initstack(&undoStack);
initstack(&redoStack);
while (1)
{
printf("\nCurrent Text: %s\n", currentText);
printf("1. Type Text\n2. Undo\n3. Redo\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar(); // to consume newline character
switch (choice)
{
case 1:
push(&undoStack, currentText);
initstack(&redoStack); // Clear redo stack
printf("Enter text to append: ");
fgets(input, MAX_TEXT, stdin);
input[strcspn(input, "\n")] = 0; // Remove newline character
strcat(currentText, input);
break;
case 2:{
if (isempty(&undoStack))
{
printf("Nothing to undo\n");
}
else
{
push(&redoStack, currentText);
strcpy(currentText, pop(&undoStack));
}
break;
}
case 3:
if (isempty(&redoStack))
{
printf("Nothing to redo\n");
}
else
{
push(&undoStack, currentText);
strcpy(currentText, pop(&redoStack));
}
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
}
getch();
return 0;
}


// 2
 
#include <stdio.h>
#include <string.h>
#define MAX 100
char students[MAX][50];
int count = 0;
void insertStudent() {
if (count < MAX) {
printf("Enter student name: ");
scanf("%s", students[count]);
count++;
printf("Student added successfully.\n");
} else {
printf("Class is full. Cannot add more students.\n");
}
}
void deleteStudent() {
if (count > 0) {
count--;
printf("Student removed successfully.\n");
} else {
printf("No students to remove.\n");
}
}
void displayStudents() {
int i;
if (count > 0) {
printf("Student Names:\n");
for (i = 0; i < count; i++) {
printf("%d. %s\n", i + 1, students[i]);
}
} else {
printf("No students to display.\n");
}
}
int main() {
int choice;
do {
printf("\nMenu:\n");
printf("1. Add Student\n");
printf("2. Remove Student\n");
printf("3. Display Students\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
insertStudent();
break;
case 2:
deleteStudent();
break;
case 3:
displayStudents();
break;
case 4:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 4);
getch();
return 0;
}