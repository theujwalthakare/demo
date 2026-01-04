// 1

#include <stdio.h>
#include <string.h>
int main()
{
int n, i, j;
char names[50][50], key[50];
printf("Enter number of students: ");
scanf("%d", &n);
printf("Enter student names:\n");
for (i = 0; i < n; i++)
{
scanf("%s", names[i]);
}
// Insertion Sort
for (i = 1; i < n; i++)
{
strcpy(key, names[i]);
j = i - 1;
while (j >= 0 && strcmp(names[j], key) > 0)
{
strcpy(names[j + 1], names[j]);
j--;
}
strcpy(names[j + 1], key);
}
printf("\nStudent names in ascending order:\n");
for (i = 0; i < n; i++)
{
printf("%s\n", names[i]);
}
return 0;
}

// 2


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