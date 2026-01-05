// Q1. Create an array to store student names in a class, allowing insertion, deletion, and traversal operations.
#include <stdio.h>
#include <string.h>
#define MAX 100
#define NAME_LEN 50
void insert(char students[][NAME_LEN], int *n, char name[]);
void delete(char students[][NAME_LEN], int *n, int pos);
void traverse(char students[][NAME_LEN], int n);
int main() {
    char students[MAX][NAME_LEN];
    int n = 0, choice, pos;
    char name[NAME_LEN];
    while (1) {
        printf("\n--- Student Management Menu ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Traverse Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (n >= MAX) {
                    printf("Class is full!\n");
                } else {
                    printf("Enter student name: ");
                    fgets(name, NAME_LEN, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    insert(students, &n, name);
              }
                break;
            case 2:
                if (n == 0) {
                    printf("No students to delete!\n");
                } else {
                    printf("Enter position to delete (1-%d): ", n);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n) {
                        printf("Invalid position!\n");
                    } else {
                        delete(students, &n, pos);
                    }
                }
                break;
            case 3:
                traverse(students, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
void insert(char students[][NAME_LEN], int *n, char name[]) {
    strcpy(students[*n], name);
    (*n)++;
    printf("Student added successfully.\n");
}
void delete(char students[][NAME_LEN], int *n, int pos) {
    int i;
    for (i = pos - 1; i < *n - 1; i++) {
        strcpy(students[i], students[i + 1]);
    }
    (*n)--;
    printf("Student deleted successfully.\n");
}
void traverse(char students[][NAME_LEN], int n) {
    int i;
    if (n == 0) {
        printf("No students in the class.\n");
    } else {
        for (i = 0; i < n; i++) {
           printf("%d. %s\n", i + 1, students[i]);
     }}}
// Q2. Write a program to store a sequence of train stations in a singly linked list and reverse the order to simulate a return journey.
  #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char station[50];
    struct node *next;
};
struct node *head = NULL;
/* Function to insert station at end */
void insertStation(char name[]) {
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->station, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
/* Function to display stations */
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("No stations available.\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->station);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Function to reverse linked list */
void reverse() {
    struct node *prev = NULL, *curr = head, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    printf("Journey reversed successfully.\n");
}
void main() {
    int choice;
    char name[50];
    clrscr();
    while (1) {
        printf("\n--- Train Journey Menu ---\n");
        printf("1. Add Station\n");
        printf("2. Display Journey\n");
        printf("3. Reverse Journey (Return Trip)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter station name: ");
                scanf("%s", name);
                insertStation(name);
                break;
            case 2:
                printf("Train Route:\n");
                display();
               break;
            case 3:
                reverse();
                break;

            case 4:
                getch();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

