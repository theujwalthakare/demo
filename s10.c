#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int patientID[MAX];
char patientName[MAX][50];
int severity[MAX];
int front = -1, rear = -1;
int isFull()
{
return rear == MAX - 1;
}
int isEmpty()
{
return front == -1;
}
void insertPatient(int id, char name[], int sev)
{
if (isFull())
{
printf("Priority Queue is full. Cannot add more patients.\n");
return;
}
// If queue is empty
if (front == -1)
front = rear = 0;
else
rear++;
int i;
// Find correct position based on priority (severity)
for (i = rear - 1; i >= front; i--)
{
if (sev > severity[i])
{
patientID[i + 1] = patientID[i];
severity[i + 1] = severity[i];
strcpy(patientName[i + 1], patientName[i]);
}
else
{
break;
}
}
// Insert patient at correct position
patientID[i + 1] = id;
severity[i + 1] = sev;
strcpy(patientName[i + 1], name);
printf("Patient inserted successfully.\n");
}
void treatPatient()
{
if (isEmpty())
{
printf("Priority Queue is empty. No patients to treat.\n");
return;
}
printf("Patient Treated: %s (ID %d, Severity %d)\n",
patientName[front], patientID[front], severity[front]);
if (front == rear)
{
front = rear = -1;
}
else
{
front++;
}
}
void displayPatients()
{
if (isEmpty())
{
printf("No patients in the queue.\n");
return;
}
printf("\n--- Current Patients in Queue ---\n");
for (int i = front; i <= rear; i++)
{
printf("ID: %d | Name: %s | Severity: %d\n",
patientID[i], patientName[i], severity[i]);
}
}
int main()
{
int choice, id, sev;
char name[50];
while (1)
{
printf("\nHospital Emergency Room Priority Queue\n");
printf("1. Insert Patient\n");
printf("2. Treat Patient\n");
printf("3. Display Patients\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter Patient ID: ");
scanf("%d", &id);
printf("Enter Patient Name: ");
scanf("%s", name);
printf("Enter Severity (higher number = more severe): ");
scanf("%d", &sev);
insertPatient(id, name, sev);
break;
case 2:
treatPatient();
break;
case 3:
displayPatients();
break;
case 4:
exit(0);
default:
printf("Invalid choice. Try again.\n");
}
}
return 0;
}

// 2

// 2
#include <stdio.h>
#include <string.h>
#define max 50
void main()
{
int i, j, students, subjects;
char names[max][50];
int marks[max][max];
float total[max], average[max];
int topperIndex = 0;
printf("Enter number of students: ");
scanf("%d", &students);
printf("Enter number of subjects: ");
scanf("%d", &subjects);
// Input student names and their marks
printf("Enter student names and their marks:\n");
for (i = 0; i < students; i++)
{
total[i] = 0; // Initialize total marks for each student
printf("Student %d name: ", i + 1);
scanf("%s", names[i]);
for (j = 0; j < subjects; j++)
{
printf("Subject %d marks: ", j + 1);
scanf("%d", &marks[i][j]);
total[i] += marks[i][j]; // Add marks to total
}
average[i] = total[i] / subjects; // Calculate average
if (average[i] > average[topperIndex])
topperIndex = i; // Update topper index
}
printf("\nMarks of students:\n");
printf("Name\t");
for (j = 0; j < subjects; j++)
{
printf("Sub%d\t", j + 1);
}
printf("Total\tAverage\n");
for (i = 0; i < students; i++)
{
printf("%s\t", names[i]);
for (j = 0; j < subjects; j++)
{
printf("%d\t", marks[i][j]);
}
printf("%.2f\t%.2f\n", total[i], average[i]);
}
printf("\nTopper: %s with Average Marks: %.2f\n", names[topperIndex], average[topperIndex]);
}