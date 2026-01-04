// 1

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct song
{
char song[50];
struct song *next;
struct song *prev;
}NODE;
NODE *head=NULL;
void create()
{
int i,n;
NODE *temp,*newnode;
printf("Enter Number of Songs:");
scanf("%d",&n);
head=(NODE *)malloc(sizeof(NODE));
head->prev=NULL;
printf("ENter Song 1:");
scanf("%s",head->song);
temp=head;
for(i=1;i<n;i++)
{
temp->next=(NODE *)malloc(sizeof(NODE));
temp->next->prev=temp;
temp=temp->next;
printf("Enter %d song:",i+1);
scanf("%s",temp->song);
}
temp->next=NULL;
}
void display()
{
NODE *temp=head;
if(head==NULL)
{
printf("The playlist is empty:\n");
return;
}
printf("Song List is:\n");
while(temp!=NULL)
{
printf("%s\n",temp->song);
temp=temp->next;
}
printf("\n\n");
}
void forward()
{
NODE *temp=head;
if(head==NULL)
{
printf("The playlist is empty:\n");
return;
}
printf("Playing songs->:\n");
while(temp!=NULL)
{
printf("%s->",temp->song);
temp=temp->next;
}
printf("\n\n");
}
void backword()
{
NODE *temp=head;
if(head==NULL)
{
printf("The playlist is empty:\n");
return;
}
printf("Playing songs in<-:\n");
while(temp->next!=NULL)
{
temp=temp->next;
}
while(temp!=NULL)
{
printf("%s->",temp->song);
temp=temp->prev;
}
printf("\n\n");
}
int main()
{
int ch;
do
{
printf("-----MENU-----\n");
printf("1:create playlist\n2:display list\n3:forward\n4:backword\n5:exit\n");
printf("Enter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:display();
break;
case 3:forward();
break;
case 4:backword();
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
#define MAX 100
int patientID[MAX];
char patientName[MAX][50];
int severity[MAX];
int front = -1, rear = -1;
int isFull()
{
return rear == MAX - 1;
}
int isEmpty()
{
return front == -1;
}
void insertPatient(int id, char name[], int sev)
{
if (isFull())
{
printf("Priority Queue is full. Cannot add more patients.\n");
return;
}
// If queue is empty
if (front == -1)
front = rear = 0;
else
rear++;
int i;
// Find correct position based on priority (severity)
for (i = rear - 1; i >= front; i--)
{
if (sev > severity[i])
{
patientID[i + 1] = patientID[i];
severity[i + 1] = severity[i];
strcpy(patientName[i + 1], patientName[i]);
}
else
{
break;
}
}
// Insert patient at correct position
patientID[i + 1] = id;
severity[i + 1] = sev;
strcpy(patientName[i + 1], name);
printf("Patient inserted successfully.\n");
}
void treatPatient()
{
if (isEmpty())
{
printf("Priority Queue is empty. No patients to treat.\n");
return;
}
printf("Patient Treated: %s (ID %d, Severity %d)\n",
patientName[front], patientID[front], severity[front]);
if (front == rear)
{
front = rear = -1;
}
else
{
front++;
}
}
void displayPatients()
{
if (isEmpty())
{
printf("No patients in the queue.\n");
return;
}
printf("\n--- Current Patients in Queue ---\n");
for (int i = front; i <= rear; i++)
{
printf("ID: %d | Name: %s | Severity: %d\n",
patientID[i], patientName[i], severity[i]);
}
}
int main()
{
int choice, id, sev;
char name[50];
while (1)
{
printf("\nHospital Emergency Room Priority Queue\n");
printf("1. Insert Patient\n");
printf("2. Treat Patient\n");
printf("3. Display Patients\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter Patient ID: ");
scanf("%d", &id);
printf("Enter Patient Name: ");
scanf("%s", name);
printf("Enter Severity (higher number = more severe): ");
scanf("%d", &sev);
insertPatient(id, name, sev);
break;
case 2:
treatPatient();
break;
case 3:
displayPatients();
break;
case 4:
exit(0);
default:
printf("Invalid choice. Try again.\n");
}
}
return 0;
}
