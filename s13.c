Q1. Implement the Bubble Sort algorithm to sort an array of student marks.
#include <stdio.h>
#include <conio.h>
void main() {
    int marks[10], n, i, j, temp;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter student marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
}
    /* Bubble Sort Logic */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }}}
    printf("Sorted marks (Ascending Order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    getch();}
Q2. Implement sequential search to check whether a student has registered for an event.
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


