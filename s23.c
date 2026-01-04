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
// Q2. Implement a music playlist where songs can be played forward and backward using a doubly linked list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char song[50];
    struct node *next, *prev;
} *head=NULL, *tail=NULL;
void addSong(char *name) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->song, name);
    n->next = NULL;
    n->prev = tail;
    if (!head) head = n;
    else tail->next = n;
    tail = n;
}
void playForward() {
    struct node *t = head;
    if (!t) { printf("Playlist empty!\n"); return; }
    while (t) { printf("%s -> ", t->song); t = t->next; }
    printf("END\n");
}
void playBackward() {
    struct node *t = tail;
   if (!t) { printf("Playlist empty!\n"); return; }
    while (t) { printf("%s -> ", t->song); t = t->prev; }
    printf("START\n");
}
void main() {
    int ch;
    char name[50];
    clrscr();
    while (1) {
        printf("\n1.Add Song 2.Play Forward 3.Play Backward 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", name);
                addSong(name);
                break;
            case 2: playForward(); break;
            case 3: playBackward(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }}}

