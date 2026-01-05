// Q1. Implement a music playlist where songs can be played forward and backward using a doubly linked list.
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

// Q2. Implement a priority queue for a hospital emergency room, where patients with higher severity are treated first.
#include <stdio.h>
#include <conio.h>
#define MAX 10
struct patient {
    int id;
    int severity;
};
struct patient pq[MAX];
int count = 0;
/* Insert patient based on priority */
void insert(int id, int severity) {
    int i;
    if (count == MAX) {
        printf("Emergency room is full!\n");
        return;
    }
    i = count - 1;
    /* Shift lower priority patients */
    while (i >= 0 && pq[i].severity < severity) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].id = id;
    pq[i + 1].severity = severity;
    count++;
    printf("Patient added successfully.\n");
}
/* Treat patient (delete highest priority) */
void treat() {
    int i;
    if (count == 0) {
        printf("No patients to treat.\n");
        return;
    }
    printf("Treating Patient ID: %d (Severity: %d)\n",
           pq[0].id, pq[0].severity);
    /* Shift remaining patients */
    for (i = 0; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }
    count--;
}
/* Display waiting patients */
void display() {
    int i;

    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }
    printf("\nPatientID  Severity\n");
    for (i = 0; i < count; i++) {
        printf("%d\t   %d\n", pq[i].id, pq[i].severity);
    }}
void main() {
    int choice, id, severity;
    clrscr();
    while (1) {
        printf("\n--- Hospital Emergency Priority Queue ---\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Severity (higher = more serious): ");
                scanf("%d", &severity);
                insert(id, severity);
                break;
            case 2:
                treat();
                break;
            case 3:
                display();
                break;
            case 4:
                getch();
                return;
            default:
                printf("Invalid choice!\n");
        }}}

