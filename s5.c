Q1. Implement binary search to find whether a given roll number exists in a sorted list.
#include <stdio.h>
#include <conio.h>
void main() {
    int roll[10], n, key;
    int low, high, mid, i;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter roll numbers in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }
    printf("Enter roll number to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (roll[mid] == key) {
            printf("Roll number %d FOUND at position %d\n", key, mid + 1);
            getch();
            return;
        }
        else if (roll[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Roll number %d NOT FOUND\n", key);
    getch();}
Q2. Implement the Bubble Sort algorithm to sort an array of student marks.
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
