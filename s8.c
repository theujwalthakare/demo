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
{Q1. Implement a stack-based text editor feature that supports undo/redo operations.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 10
#define SIZE 100
char undoStack[MAX][SIZE];
char redoStack[MAX][SIZE];
int undoTop = -1, redoTop = -1;
char text[SIZE] = "";
/* Push to undo stack */
void pushUndo(char str[]) {
    if (undoTop < MAX - 1) {
        undoTop++;
        strcpy(undoStack[undoTop], str);
    }
}
/* Push to redo stack */
void pushRedo(char str[]) {
    if (redoTop < MAX - 1) {
        redoTop++;
        strcpy(redoStack[redoTop], str);
    }
}
/* Pop from undo stack */
int popUndo(char str[]) {
    if (undoTop >= 0) {
        strcpy(str, undoStack[undoTop]);
        undoTop--;
        return 1;
    }
    return 0;
}
/* Pop from redo stack */
int popRedo(char str[]) {
    if (redoTop >= 0) {
        strcpy(str, redoStack[redoTop]);
        redoTop--;
        return 1;
    }
    return 0;
}
/* Clear redo stack after new edit */
void clearRedo() {
    redoTop = -1;
}
void main() {
    int choice;
    char newText[SIZE];
    clrscr();
    while (1) {
        printf("\n--- Stack Based Text Editor ---\n");
        printf("Current Text: \"%s\"\n", text);
        printf("1. Edit Text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                pushUndo(text);   /* Save current state */
                clearRedo();      /* Clear redo after edit */
                printf("Enter new text: ");
                scanf("%s", newText);
                strcpy(text, newText);
                break;
            case 2:
                if (popUndo(newText)) {
                    pushRedo(text);
                    strcpy(text, newText);
                    printf("Undo successful.\n");
                } else {
                    printf("Nothing to undo.\n");
                }
                break;
            case 3:
                if (popRedo(newText)) {
                    pushUndo(text);
                    strcpy(text, newText);
                    printf("Redo successful.\n");
                } else {
                    printf("Nothing to redo.\n");
                }
                break;
            case 4:
                getch();
                return;
            default:
                printf("Invalid choice!\n");
        }}}
Q2. Create an array to store student names in a class, allowing insertion, deletion, and traversal operations.
#include <stdio.h>
#include <string.h>
#define MAX 100
#define NAME_LEN 50
void insert(char students[][NAME_LEN], int *n, char name[]);
void delete(char students[][NAME_LEN], int *n, int pos);
void traverse(char students[][NAME_LEN], int n);
int main() {
    char students[MAX][NAME_LEN];
    int n = 0, choice, pos;
    char name[NAME_LEN];
    while (1) {
        printf("\n--- Student Management Menu ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Traverse Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (n >= MAX) {
                    printf("Class is full!\n");
                } else {
                    printf("Enter student name: ");
                    fgets(name, NAME_LEN, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    insert(students, &n, name);
              }
                break;
            case 2:
                if (n == 0) {
                    printf("No students to delete!\n");
                } else {
                    printf("Enter position to delete (1-%d): ", n);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n) {
                        printf("Invalid position!\n");
                    } else {
                        delete(students, &n, pos);
                    }
                }
                break;
            case 3:
                traverse(students, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
void insert(char students[][NAME_LEN], int *n, char name[]) {
    strcpy(students[*n], name);
    (*n)++;
    printf("Student added successfully.\n");
}
void delete(char students[][NAME_LEN], int *n, int pos) {
    int i;
    for (i = pos - 1; i < *n - 1; i++) {
        strcpy(students[i], students[i + 1]);
    }
    (*n)--;
    printf("Student deleted successfully.\n");
}
void traverse(char students[][NAME_LEN], int n) {
    int i;
    if (n == 0) {
        printf("No students in the class.\n");
    } else {
        for (i = 0; i < n; i++) {
           printf("%d. %s\n", i + 1, students[i]);
     }}}




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