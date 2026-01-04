#include <stdio.h>
int main() {
int n, i, low, high, mid, key;
int roll[100];
printf("Enter number of students: ");
scanf("%d", &n);
printf("Enter the roll numbers in sorted order:\n");
for (i = 0; i < n; i++) {
scanf("%d", &roll[i]);
}
printf("Enter the roll number to search: ");
scanf("%d", &key);
low = 0;
high = n - 1;
// Binary Search
while (low <= high) {
mid = (low + high) / 2;
if (roll[mid] == key) {
printf("Roll number %d found at position %d.\n", key, mid + 1);
return 0;
}
else if (key < roll[mid]) {
high = mid - 1;
}
else {
low = mid + 1;
}
}
printf("Roll number %d not found in the list.\n", key);
getch();
}


// 2
#include <stdio.h>
int main() {
int n, i, j, temp;
int marks[100];
printf("Enter number of students: ");
scanf("%d", &n);
printf("Enter the marks of the students:\n");
for (i = 0; i < n; i++) {
scanf("%d", &marks[i]);
}
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - 1 - i; j++) {
// Compare adjacent elements
if (marks[j] > marks[j + 1]) {
temp = marks[j];
marks[j] = marks[j + 1];
marks[j + 1] = temp;
}
}
}
printf("\nSorted marks in ascending order:\n");
for (i = 0; i < n; i++) {
printf("%d ", marks[i]);
}
return 0;
}