// Q1. Use the stack ADT to check whether parentheses in an arithmetic expression are balanced.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50
char stack[MAX];
int top = -1;
/* Push operation */
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}
/* Pop operation */
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}
void main() {
    char exp[MAX];
    int i, flag = 1;
    clrscr();
    printf("Enter expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push('(');
        } else if (exp[i] == ')') {
            if (top == -1) {
                flag = 0;
                break;
            }
            pop();
        }}
    if (top != -1)
        flag = 0;
    if (flag)
        printf("Parentheses are BALANCED\n");
    else
        printf("Parentheses are NOT BALANCED\n");
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
                printf("Invalid choice!\n");}}}


