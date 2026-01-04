#include <stdio.h>
#include <string.h>
void main()
{
int n, i, found = 0;
char students[50][50], searchName[50];
printf("Enter number of registered students: ");
scanf("%d", &n);
printf("Enter student names:\n");
for (i = 0; i < n; i++)
{
scanf("%s", students[i]);
}
printf("Enter student name to check registration: ");
scanf("%s", searchName);
for (i = 0; i < n; i++)
{
if (strcmp(students[i], searchName) == 0)
{
found = 1;
break;
}
}
if (found)
printf("%s is registered for the event.\n", searchName);
else
printf("%s is NOT registered for the event.\n", searchName);
return 0;
}


// 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
typedef struct Student {
int roll;
char name[50];
float marks;
} Std;
typedef struct Node {
Std data;
struct Node *left;
struct Node *right;
}NODE;
NODE* create(Std s)
{
NODE* newnode = (NODE*) malloc(sizeof(NODE));
newnode->data = s;
newnode->left = newnode->right = NULL;
return newnode;
}
NODE *insert(NODE *root,Std s)
{
if(root==NULL)
return create(s);
if(s.roll<root->data.roll)
root->left=insert(root->left,s);
else
root->right=insert(root->right,s);
return root;
}
NODE* search(NODE* root, int roll)
{
if (root == NULL || root->data.roll == roll)
return root;
if (roll < root->data.roll)
return search(root->left, roll);
return search(root->right, roll);
}
void inorder(NODE *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("Roll:%d | Name:%s | Marks:%2f \n",
root->data.roll,root->data.name,root->data.marks);
inorder(root->right);
}
}
void main()
{
NODE *root=NULL;
Std s;
int ch,roll;
NODE *result;
clrscr();
do{
printf("1:Insert Student\n2:Search Student\n3:Display Student\n4:Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter Roll Number:");
scanf("%d",&s.roll);
printf("Enter Name:");
scanf("%s",s.name);
printf("Enter marks:");
scanf("%f",&s.marks);
root=insert(root,s);
printf("Student Record Inserted succesfully!!\n");
break;
case 2:printf("Enter Roll Number to Search: ");
scanf("%d", &roll);
result = search(root, roll);
if (result != NULL)
{
printf("Record Found!\n");
printf("Roll: %d | Name: %s | Marks: %.2f\n",
result->data.roll, result->data.name, result->data.marks);
}
else
{
printf("Student not found!\n");
}
break;
case 3:printf("------Student Details Are----\n");
inorder(root);
break;
case 4:exit(0);
}
}while(ch!=4);
getch();
}