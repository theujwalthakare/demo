#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
int id;
int marks;
char name[50];
struct student *next;
}NODE;
NODE *head=NULL;
void create()
{
int i,n;
NODE *temp;
printf("Enter Number of student:\n");
scanf("%d",&n);
head=(NODE*)malloc(sizeof(NODE));
printf("Enter student 1 details:\n");
printf("Enter Student id:");
scanf("%d",&head->id);
printf("Enter student name:");
scanf("%s",head->name);
printf("Enter Student marks:");
scanf("%d",&head->marks);
temp=head;
for(i=1;i<n;i++)
{
temp->next=(NODE*)malloc(sizeof(NODE));
temp=temp->next;
printf("Enter Student details of %d\n",i+1);
printf("Enter Student id:");
scanf("%d",&temp->id);
printf("Enter student name:");
scanf("%s",temp->name);
printf("Enter Student marks:");
scanf("%d",&temp->marks);
}
temp->next=NULL;
}
void display()
{
NODE *temp;
printf("ID\tName\tMarks\t\n");
for(temp=head;temp!=NULL;temp=temp->next)
{
printf("%d\t",temp->id);
printf("%s\t",temp->name);
printf("%d\t\n",temp->marks);
}
}
void insert()
{
int i,pos;
NODE *newnode,*temp;
printf("Enter Position to insert:");
scanf("%d",&pos);
newnode=(NODE*)malloc(sizeof(NODE));
printf("Enter Node to insert:\n");
printf("Enter Student id:");
scanf("%d",&newnode->id);
printf("Enter student name:");
scanf("%s",newnode->name);
printf("Enter Student marks:");
scanf("%d",&newnode->marks);
temp=head;
while(i<pos-1 && temp!=NULL)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
}
void deleteNode()
{
int id;
NODE *temp = head, *prev = NULL;
if (head == NULL)
{
printf("\nList is empty.\n");
return;
}
printf("Enter ID of student to delete: ");
scanf("%d", &id);
// If the head node is to be deleted
if (head->id == id)
{
head = head->next;
free(temp);
printf("Record deleted successfully.\n");
return;
}
// Traverse and find the node
while (temp != NULL && temp->id != id)
{
prev = temp;
temp = temp->next;
}
if (temp == NULL)
{
printf("Record not found!\n");
return;
}
prev->next = temp->next;
free(temp);
printf("Record deleted successfully.\n");
}
int main()
{
int ch;
do
{
printf("1:create\n2:insert\n3:delete\n4:Display\n5:exit\n");
printf("Enter Choice");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:insert();
break;
case 3:deleteNode();
break;
case 4:display();
break;
case 5:break;
}
}while(ch!=5);
getch();
return 0;
}

// 2
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