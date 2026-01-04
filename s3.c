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
#include <string.h>
#define max 50
void main()
{
int i, j, students, subjects;
char names[max][50];
int marks[max][max];
float total[max], average[max];
int topperIndex = 0;
printf("Enter number of students: ");
scanf("%d", &students);
printf("Enter number of subjects: ");
scanf("%d", &subjects);
// Input student names and their marks
printf("Enter student names and their marks:\n");
for (i = 0; i < students; i++)
{
total[i] = 0; // Initialize total marks for each student
printf("Student %d name: ", i + 1);
scanf("%s", names[i]);
for (j = 0; j < subjects; j++)
{
printf("Subject %d marks: ", j + 1);
scanf("%d", &marks[i][j]);
total[i] += marks[i][j]; // Add marks to total
}
average[i] = total[i] / subjects; // Calculate average
if (average[i] > average[topperIndex])
topperIndex = i; // Update topper index
}
printf("\nMarks of students:\n");
printf("Name\t");
for (j = 0; j < subjects; j++)
{
printf("Sub%d\t", j + 1);
}
printf("Total\tAverage\n");
for (i = 0; i < students; i++)
{
printf("%s\t", names[i]);
for (j = 0; j < subjects; j++)
{
printf("%d\t", marks[i][j]);
}
printf("%.2f\t%.2f\n", total[i], average[i]);
}
printf("\nTopper: %s with Average Marks: %.2f\n", names[topperIndex], average[topperIndex]);
}