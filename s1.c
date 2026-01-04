
// Q1
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

// Q2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
typedef struct train {
char data[20];
struct train *next;
} NODE;
NODE *head = NULL;
void create() {
int n, i;
NODE *temp;
printf("Enter Number of Trains: ");
scanf("%d", &n);
head = (NODE*)malloc(sizeof(NODE));
printf("Enter Train 1 Name: ");
scanf("%s", head->data);
temp = head;
for (i = 1; i < n; i++) {
temp->next = (NODE*)malloc(sizeof(NODE));
temp=temp->next;
printf("Enter Train %d Name: ", i + 1);
scanf("%s", temp->data);
}
temp->next = NULL;
}
void display() {
NODE *temp = head;
if (temp == NULL) {
printf("No trains in the list.\n");
return;
}
printf("\nTrain List:\n");
while (temp != NULL) {
printf("%s -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
void reverse()
{
NODE *prev = NULL;
NODE *temp = head;
NODE *next = NULL;
while (temp != NULL) {
next = temp->next;
temp->next = prev;
prev =temp;
temp = next;
}
head = prev;
printf("\nReversed Train List:\n");
display();
}
int main() {
create();
display();
reverse();
getch();
return 0;}
