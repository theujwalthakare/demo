/*
Assignment Slip – 24
1. Design a class for a Student Database that allows the addition, deletion, and search of 
student records using static members and friend functions.
*/
#include <iostream.h> 
#include <conio.h> 
#include <string.h> 
 
class Student { 
private: 
    int rollNo; 
    char name[50]; 
    static int totalStudents;   
 
public: 
    Student() { 
        rollNo = 0; 
        strcpy(name, ""); 
    } 
 
   
    void input() { 
        cout << "Enter Roll Number: "; 
        cin >> rollNo; 
        cout << "Enter Name: "; 
        cin >> name; 
        totalStudents++; 
    } 
 
    
    void display() { 
        cout << "Roll No: " << rollNo << ", Name: " << name << endl; 
    } 
 
    friend void searchStudent(Student students[], int n, int r); 
 
    friend void deleteStudent(Student students[], int &n, int r); 
    static void showTotalStudents() { 
        cout << "Total Students: " << totalStudents << endl; 
    } 
}; 
int Student::totalStudents = 0; 
 
void searchStudent(Student students[], int n, int r) { 
    int i; 
    for(i = 0; i < n; i++) { 
        if(students[i].rollNo == r) { 
            cout << "Student Found: "; 
            students[i].display(); 
            return; 
        } 
    } 
    cout << "Student with Roll No " << r << " not found.\n"; 
} 
 
void deleteStudent(Student students[], int &n, int r) { 
    int i, pos = -1; 
    for(i = 0; i < n; i++) { 
        if(students[i].rollNo == r) { 
            pos = i; 
            break; 
        } 
    } 
    if(pos == -1) { 
        cout << "Student with Roll No " << r << " not found.\n"; 
        return; 
    } 
    for(i = pos; i < n - 1; i++) { 
        students[i] = students[i + 1]; 
    } 
    n--;   
    Student::totalStudents--; 
    cout << "Student deleted successfully.\n"; 
} 
 
void main() { 
    clrscr(); 
    Student students[50];  
    int n = 0;              
    int choice; 
 
    do { 
        cout << "\n------ Student Database Menu ------\n"; 
        cout << "1. Add Student\n"; 
        cout << "2. Display All Students\n"; 
        cout << "3. Search Student\n"; 
        cout << "4. Delete Student\n"; 
        cout << "5. Show Total Students\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                cout << "Enter Student Details:\n"; 
                students[n].input(); 
                n++; 
                break; 
 
            case 2: 
                if(n == 0) 
                    cout << "No student records found.\n"; 
                else { 
                    cout << "Student Records:\n"; 
                    for(int i = 0; i < n; i++) 
                        students[i].display(); 
                } 
                break; 
 
            case 3: 
                if(n == 0) 
                    cout << "No student records to search.\n"; 
                else { 
                    int r; 
                    cout << "Enter Roll Number to search: "; 
                    cin >> r; 
                    searchStudent(students, n, r); 
                } 
                break; 
 
            case 4: 
                if(n == 0) 
                    cout << "No student records to delete.\n"; 
                else { 
                    int r; 
                    cout << "Enter Roll Number to delete: "; 
                    cin >> r; 
                    deleteStudent(students, n, r); 
                } 
                break; 
 
            case 5: 
                Student::showTotalStudents(); 
                break; 
 
            case 6: 
                cout << "Exiting program. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
 
    } while(choice != 6); 
 
    getch();  
} 


/*
2 Create a program using hybrid inheritance to model academic and extracurricular 
performance and resolve ambiguity using virtual base classes
*/
#include <iostream.h> 
#include <conio.h> 
 
class Student { 
protected: 
    char name[50]; 
    int rollNo; 
public: 
    void inputStudent() { 
        cout << "Enter Student Name: "; 
        cin >> name; 
        cout << "Enter Roll Number: "; 
        cin >> rollNo; 
    } 
 
    void displayStudent() { 
        cout << "Student: " << name << ", Roll No: " << rollNo << endl; 
    } 
}; 
 
class Academic : virtual public Student { 
protected: 
    float marks; 
public: 
    void inputAcademic() { 
        cout << "Enter Academic Marks (0-100): "; 
        cin >> marks; 
    } 
 
    void displayAcademic() { 
        cout << "Academic Marks: " << marks << endl; 
    } 
}; 
 
class Extracurricular : virtual public Student { 
protected: 
    int activitiesScore; 
public: 
    void inputExtracurricular() { 
        cout << "Enter Extracurricular Score (0-100): "; 
        cin >> activitiesScore; 
    } 
 
    void displayExtracurricular() { 
        cout << "Extracurricular Score: " << activitiesScore << endl; 
    } 
}; 
 
 
class Result : public Academic, public Extracurricular { 
public: 
    void displayResult() { 
        displayStudent();          
        displayAcademic(); 
        displayExtracurricular(); 
 
        float total = marks + activitiesScore; 
        cout << "Total Performance Score: " << total << endl; 
 
        if(total >= 150) 
            cout << "Grade: A\n"; 
        else if(total >= 120) 
            cout << "Grade: B\n"; 
        else if(total >= 90) 
            cout << "Grade: C\n"; 
        else 
            cout << "Grade: D\n"; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    Result *r = new Result();   
 
    cout << "Enter Student Details:\n"; 
    r->inputStudent(); 
    r->inputAcademic(); 
    r->inputExtracurricular(); 
 
    cout << "\n----- Student Performance -----\n"; 
    r->displayResult(); 
 
    delete r;  
    getch(); 
} 
