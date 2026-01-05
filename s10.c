Q1. Implement a priority queue for a hospital emergency room, where patients with higher severity are treated first.
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

