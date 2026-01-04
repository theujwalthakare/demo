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
#include <string.h>
#include <conio.h>
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