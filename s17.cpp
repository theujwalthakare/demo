/*
Assignment Slip – 17
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
2. Create a pointer-based implementation of a class where objects are dynamically created 
and manipulated using the this pointer and constructors/destructors
*/
#include <iostream.h> 
#include <conio.h> 
#include <stdlib.h>  
 
class Box { 
private: 
    int length; 
    int width; 
    int height; 
 
public: 
  
    Box(int l = 0, int w = 0, int h = 0) { 
        length = l; 
        width = w; 
        height = h; 
        cout << "Constructor called for Box at " << this << endl; 
    } 
 
 
    ~Box() { 
        cout << "Destructor called for Box at " << this << endl; 
    } 
 
 
    void setDimensions(int l, int w, int h) { 
        this->length = l; 
        this->width = w; 
        this->height = h; 
    } 
 
 
    int volume() { 
        return length * width * height; 
    } 
 
  
    void display() { 
        cout << "Box at " << this  
             << " [L=" << length  
             << ", W=" << width  
             << ", H=" << height  
             << ", Volume=" << volume()  
             << "]\n"; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    int choice; 
    Box *b = NULL;   
 
    do { 
        cout << "\n------ Pointer-Based Box Menu ------\n"; 
        cout << "1. Create Box\n"; 
        cout << "2. Set Dimensions\n"; 
        cout << "3. Display Box\n"; 
        cout << "4. Delete Box\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                if(b == NULL) { 
                    b = new Box();   
                    cout << "Box created dynamically at " << b << endl; 
                } else { 
                    cout << "Box already exists at " << b << endl; 
                } 
                break; 
 
            case 2: 
                if(b != NULL) { 
                    int l, w, h; 
                    cout << "Enter Length, Width, Height: "; 
                    cin >> l >> w >> h; 
                    b->setDimensions(l, w, h); 
                    cout << "Dimensions set successfully.\n"; 
                } else { 
                    cout << "No Box exists. Create a box first.\n"; 
                } 
                break; 
 
            case 3: 
                if(b != NULL) { 
                    b->display(); 
                } else { 
                    cout << "No Box exists. Create a box first.\n"; 
                } 
                break; 
 
            case 4: 
                if(b != NULL) { 
                    delete b;  // Calls destructor 
                    b = NULL; 
                    cout << "Box deleted successfully.\n"; 
                } else { 
                    cout << "No Box exists to delete.\n"; 
                } 
                break; 
 
            case 5: 
                cout << "Exiting program. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
    } while(choice != 5); 
 
    getch();   
}