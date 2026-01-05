Q1. Implement a student record system using a singly linked list that supports creating, inserting, 
deleting, and displaying student records.
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
Q2. Write a program to store a sequence of train stations in a singly linked list and reverse the order to simulate a return journey.
  #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char station[50];
    struct node *next;
};
struct node *head = NULL;
/* Function to insert station at end */
void insertStation(char name[]) {
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->station, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }}
/* Function to display stations */
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("No stations available.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->station);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Function to reverse linked list */
void reverse() {
    struct node *prev = NULL, *curr = head, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    printf("Journey reversed successfully.\n");
}
void main() {
    int choice;
    char name[50];
    clrscr();
    while (1) {
        printf("\n--- Train Journey Menu ---\n");
        printf("1. Add Station\n");
        printf("2. Display Journey\n");
        printf("3. Reverse Journey (Return Trip)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter station name: ");
                scanf("%s", name);
                insertStation(name);
                break;
            case 2:
                printf("Train Route:\n");
                display();
               break;
            case 3:
                reverse();
                break;
            case 4:
                getch();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }}}


