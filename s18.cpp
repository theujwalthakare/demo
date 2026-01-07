/*
Assignment Slip – 18
1. Implement a multi-level inheritance model representing an organization hierarchy and 
demonstrate method overriding and virtual functions.
*/
#include <iostream.h> 
#include <conio.h> 
 
class Employee { 
protected: 
    char name[50]; 
    int id; 
 
public: 
    void inputEmployee() { 
        cout << "Enter Employee Name: "; 
        cin >> name; 
        cout << "Enter Employee ID: "; 
        cin >> id; 
    } 
 
    virtual void displayRole() {  
        cout << "Employee: " << name << ", ID: " << id << endl; 
    } 
}; 
 
class Manager : public Employee { 
protected: 
    int teamSize; 
 
public: 
    void inputManager() { 
        inputEmployee(); 
        cout << "Enter Team Size: "; 
        cin >> teamSize; 
    } 
 
    void displayRole() {   
        cout << "Manager: " << name << ", ID: " << id  
             << ", Team Size: " << teamSize << endl; 
    } 
}; 
 
class Director : public Manager { 
private: 
    char department[50]; 
 
public: 
    void inputDirector() { 
        inputManager(); 
        cout << "Enter Department: "; 
        cin >> department; 
    } 
 
    void displayRole() {   
        cout << "Director: " << name << ", ID: " << id  
             << ", Team Size: " << teamSize  
             << ", Department: " << department << endl; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    Employee *emp; 
    int choice; 
 
    do { 
        cout << "\n------ Organization Hierarchy Menu ------\n"; 
        cout << "1. Add Employee\n"; 
        cout << "2. Add Manager\n"; 
        cout << "3. Add Director\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: { 
                Employee e; 
                e.inputEmployee(); 
                emp = &e; 
                cout << "\nDisplaying using Virtual Function:\n"; 
                emp->displayRole(); 
                break; 
            } 
 
            case 2: { 
                Manager m; 
                m.inputManager(); 
                emp = &m;   
                cout << "\nDisplaying using Virtual Function:\n"; 
                emp->displayRole();   
                break; 
            } 
 
            case 3: { 
                Director d; 
                d.inputDirector(); 
                emp = &d;   
                cout << "\nDisplaying using Virtual Function:\n"; 
                emp->displayRole();  
                break; 
            } 
 
            case 4: 
                cout << "Exiting program. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
    } while(choice != 4); 
 
    getch();   
} 

/*
2. Create a program using hybrid inheritance to model academic and extracurricular 
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