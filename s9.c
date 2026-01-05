Q1. Implement a queue to simulate a customer service system where customers join and leave in FIFO order.
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
Q2. Use the stack ADT to check whether parentheses in an arithmetic expression are balanced.
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

