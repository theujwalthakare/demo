// Q1. Implement the Insertion Sort algorithm to sort student names in ascending order.
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
// Q2. Create an array to store student names in a class, allowing insertion, deletion, and traversal operations.
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

