Q1. Implement a music playlist where songs can be played forward and backward using a doubly linked list.
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
        }
    }
}
Q2. Store and display marks of students in multiple subjects using a 2D array.
#include <stdio.h>
#include <conio.h>
#define STUDENTS 3
#define SUBJECTS 3
void main() {
    int marks[STUDENTS][SUBJECTS];
    int i, j;
    clrscr();
    // Input marks
    for(i=0; i<STUDENTS; i++) {
        printf("Enter marks for Student %d:\n", i+1);
        for(j=0; j<SUBJECTS; j++) {
            printf("  Subject %d: ", j+1);
            scanf("%d", &marks[i][j]);
        }
    }
    // Display marks
    printf("\n--- Marks of Students ---\n");
    for(i=0; i<STUDENTS; i++) {
        printf("Student %d: ", i+1);
        for(j=0; j<SUBJECTS; j++) {
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }
getch();
}



