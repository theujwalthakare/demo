Q1. Implement the Insertion Sort algorithm to sort student names in ascending order.
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
Q2. Develop a BST to store and search for student records based on roll numbers.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int roll;
    char name[30];
    struct node *left, *right;
};
/* Create new BST node */
struct node* createNode(int roll, char name[]) {
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->roll = roll;
    strcpy(n->name, name);
    n->left = n->right = NULL;
    return n;
}
/* Insert node into BST */
struct node* insert(struct node *root, int roll, char name[]) {
    if (root == NULL)
        return createNode(roll, name);
    if (roll < root->roll)
        root->left = insert(root->left, roll, name);
    else if (roll > root->roll)
        root->right = insert(root->right, roll, name);
    return root;
}
/* Search student by roll number */
void search(struct node *root, int roll) {
    if (root == NULL) {
        printf("Student record NOT FOUND\n");
        return;
    }
    if (root->roll == roll) {
        printf("Student FOUND\n");
        printf("Roll No: %d\nName: %s\n", root->roll, root->name);
    }
    else if (roll < root->roll)
        search(root->left, roll);
    else
        search(root->right, roll);
}
/* Inorder traversal (display records) */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d  %s\n", root->roll, root->name);
        inorder(root->right);
    }}
void main() {
    struct node *root = NULL;
    int choice, roll;
    char name[30];
    clrscr();
    while (1) {
        printf("\n--- Student Record BST ---\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Display All (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf("%s", name);
                root = insert(root, roll, name);
                break;
            case 2:
                printf("Enter Roll Number to Search: ");
                scanf("%d", &roll);
                search(root, roll);
                break;
            case 3:
                printf("\nRoll  Name\n");
                inorder(root);
                break;
            case 4:
                getch();
                return;
            default:
                printf("Invalid choice!\n");
        }}}

