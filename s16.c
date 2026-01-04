// Q1. Implement a student record system using a singly linked list that supports creating, inserting, 
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
// Q2. Implement a queue to simulate a customer service system where customers join and leave in FIFO order.
#include <stdio.h>
#include <conio.h>
#define MAX 10
#define NAME_LEN 30
char queue[MAX][NAME_LEN];
int front = -1, rear = -1;
/* Enqueue: Customer joins queue */
void enqueue(char name[]) {
    int i;
    if (rear == MAX - 1) {
        printf("Queue is full. No more customers.\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear++;
    for (i = 0; name[i] != '\0'; i++)
        queue[rear][i] = name[i];
    queue[rear][i] = '\0';
    printf("Customer added to queue.\n");
}
/* Dequeue: Customer leaves queue */
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. No customers to serve.\n");
        return;
    }
    printf("Customer served: %s\n", queue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}
/* Display queue */
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
   }
    printf("Current Queue:\n");
    for (i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }}
void main() {
    int choice;
    char name[NAME_LEN];
    clrscr();
    while (1) {
        printf("\n--- Customer Service Queue ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                getch();
                return;
            default:
                printf("Invalid choice!\n");
        }}}

