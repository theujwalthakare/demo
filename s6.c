Q1. Implement sequential search to check whether a student has registered for an event.
#include <stdio.h>
#include <conio.h>
void main() {
    int reg[10], n, key;
    int i, found = 0;
    clrscr();
    printf("Enter number of registered students: ");
    scanf("%d", &n);
    printf("Enter registration numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &reg[i]);
    }
    printf("Enter student registration number to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (reg[i] == key) {
            found = 1;
            printf("Student IS REGISTERED at position %d\n", i + 1);
            break;
        }}
    if (!found)
        printf("Student is NOT REGISTERED\n");
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
