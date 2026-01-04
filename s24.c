// Q1. Implement a stack-based text editor feature that supports undo/redo operations.
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
// Q2. Implement a student record system using a singly linked list that supports creating, inserting, 
// deleting, and displaying student records.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int roll;
    char name[30];
    struct student *next;
};
struct student *head = NULL;
/* Create / Insert student at end */
void insertStudent(int roll, char name[]) {
    struct student *newNode, *temp;
    newNode = (struct student *)malloc(sizeof(struct student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student record inserted successfully.\n");
}
/* Delete student by roll number */
void deleteStudent(int roll) {
    struct student *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("No student records to delete.\n");
        return;
    }
    if (head->roll == roll) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student record deleted.\n");
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Student record deleted.\n");
}}
/* Display all student records */
void display() {
    struct student *temp;
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }
    printf("\nRoll No\tName\n");
    printf("------------------\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\t%s\n", temp->roll, temp->name);
        temp = temp->next;
    }}
void main() {
    int choice, roll;
    char name[30];
    clrscr();
    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf("%s", name);
                insertStudent(roll, name);
                break;
            case 2:
                printf("Enter Roll Number to Delete: ");
                scanf("%d", &roll);
                deleteStudent(roll);
                break;
            case 3:
                display();
                break;
            case 4:
                getch();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }}}

