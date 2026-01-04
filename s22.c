// Q1. Implement the Insertion Sort algorithm to sort student names in ascending order.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 10
#define LEN 30
void main() {
    char names[MAX][LEN], temp[LEN];
    int n, i, j;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter student names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    /* Insertion Sort Logic */
    for (i = 1; i < n; i++) {
        strcpy(temp, names[i]);
        j = i - 1;
        while (j >= 0 && strcmp(names[j], temp) > 0) {
            strcpy(names[j + 1], names[j]);
            j--;
        }
        strcpy(names[j + 1], temp);
    }
    printf("\nSorted Student Names (Ascending Order):\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    getch();}
// Q2. Write a program to store a sequence of train stations in a singly linked list and reverse the order to simulate a return journey.
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

