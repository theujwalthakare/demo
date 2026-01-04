// 1
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#define size 100
int ID[size];
char Name[size][50];
int front = -1;
int rear = -1;
int isFull() {
return rear == size - 1;
}
int isEmpty() {
return front == -1;
}
void enqueue(int id, char name[]) {
if (isFull()) {
printf("Queue is full. Cannot add more customers.\n");
return;
}
if (front == -1)
front = 0;
rear++;
ID[rear] = id;
strcpy(Name[rear], name);
printf("Customer Added %s with ID %d added to the queue.\n", name, id);
}
void dequeue() {
if (isEmpty()) {
printf("Queue is empty. No customers to serve.\n");
return;
}
printf("Customer Served: %s with ID %d has been served and removed from the queue.\n",
Name[front], ID[front]);
if (front == rear)
front = rear = -1;
else
front++;
}
void display() {
int i;
if (isEmpty()) {
printf("Queue is empty. No customers in the queue.\n");
return;
}
printf("Current Customers in Queue:\n");
for (i = front; i <= rear; i++) {
printf("ID: %d, Name: %s\n", ID[i], Name[i]);
}
}
int main() {
int choice, id;
char name[50];
while (1) {
printf("\nCustomer Service Queue Menu:\n");
printf("1. Add Customer\n");
printf("2. Serve Customer\n");
printf("3. Display Customers\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter Customer ID: ");
scanf("%d", &id);
printf("Enter Customer Name: ");
scanf("%s", name);
enqueue(id, name);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("Exiting the program.\n");
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
getch();
return 0;
}

// 2
// 2
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 100
typedef struct
{
char items[MAX];
int top;
} Stack;
void initstack(Stack *s)
{
s->top = -1;
}
int isfull(Stack *s)
{
return s->top == MAX - 1;
}
int isempty(Stack *s)
{
return s->top == -1;
}
void push(Stack *s, char c)
{
if (isfull(s ))
{
printf("Stack is full\n");
return;
}
s->items[++(s->top)] = c;
}
char pop(Stack *s)
{
if (isempty(s))
{
printf("Stack is empty\n");
return NULL;
}
return s->items[(s->top)--];
}
int matching(char open, char close)
{
return (open == '(' && close == ')') ||
(open == '{' && close == '}') ||
(open == '[' && close == ']');
}
int balanced(const char *expr)
{
Stack s;
int i;
char popped;
initstack(&s);
for ( i = 0; expr[i] != '\0'; i++)
{
char c = expr[i];
if (c == '(' || c == '{' || c == '[')
{
push(&s, c);
}
else if (c == ')' || c == '}' || c == ']')
{
if (isempty(&s) )
{
return 0; // Not balanced
}
popped = pop(&s);
if (!matching(popped, c))
{
return 0; // Not balanced
}
}
}
return isempty(&s); // Balanced if stack is empty
}
int main()
{
char expr[MAX];
printf("Enter an arithmetic expression: ");
scanf("%s", expr);
// Remove newline character if present
if (balanced(expr))
{
printf("The parentheses are balanced.\n");
}
else
{
printf("The parentheses are not balanced.\n");
}
getch();
return 0;
}
