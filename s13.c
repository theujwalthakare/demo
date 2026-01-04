// 1
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

// 2

#include <stdio.h>
#include <string.h>
void main()
{
int n, i, found = 0;
char students[50][50], searchName[50];
printf("Enter number of registered students: ");
scanf("%d", &n);
printf("Enter student names:\n");
for (i = 0; i < n; i++)
{
scanf("%s", students[i]);
}
printf("Enter student name to check registration: ");
scanf("%s", searchName);
for (i = 0; i < n; i++)
{
if (strcmp(students[i], searchName) == 0)
{
found = 1;
break;
}
}
if (found)
printf("%s is registered for the event.\n", searchName);
else
printf("%s is NOT registered for the event.\n", searchName);
return 0;
}

