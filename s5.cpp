/*
Assignment Slip – 5
1. Design a payroll system using run-time polymorphism (abstract classes + pure virtual 
functions) for different employee types (hourly, salaried, contractual).
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
 
    virtual void calculatePay() = 0;   
    virtual void displayPay() = 0;     
}; 
 
 
class HourlyEmployee : public Employee { 
private: 
    float hoursWorked; 
    float ratePerHour; 
    float pay; 
public: 
    void inputDetails() { 
        inputEmployee(); 
        cout << "Enter Hours Worked: "; 
        cin >> hoursWorked; 
        cout << "Enter Rate per Hour: "; 
        cin >> ratePerHour; 
    } 
 
    void calculatePay() { 
        pay = hoursWorked * ratePerHour; 
    } 
 
    void displayPay() { 
        cout << "Hourly Employee: " << name << ", ID: " << id << endl; 
        cout << "Pay: Rs. " << pay << endl; 
    } 
}; 
 
class SalariedEmployee : public Employee { 
private: 
    float monthlySalary; 
public: 
    void inputDetails() { 
        inputEmployee(); 
        cout << "Enter Monthly Salary: "; 
        cin >> monthlySalary; 
    } 
 
    void calculatePay() { 
       
    } 
 
    void displayPay() { 
        cout << "Salaried Employee: " << name << ", ID: " << id << endl; 
        cout << "Pay: Rs. " << monthlySalary << endl; 
    } 
}; 
 
class ContractualEmployee : public Employee { 
private: 
    float contractAmount; 
public: 
    void inputDetails() { 
        inputEmployee(); 
        cout << "Enter Contract Amount: "; 
        cin >> contractAmount; 
    } 
 
    void calculatePay() { 
        
    } 
 
    void displayPay() { 
        cout << "Contractual Employee: " << name << ", ID: " << id << endl; 
        cout << "Pay: Rs. " << contractAmount << endl; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    Employee *emp;  
    int choice; 
 
    do { 
        cout << "\n------ Payroll System Menu ------\n"; 
        cout << "1. Hourly Employee\n"; 
        cout << "2. Salaried Employee\n"; 
        cout << "3. Contractual Employee\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: { 
                HourlyEmployee h; 
                h.inputDetails(); 
                emp = &h;      // Polymorphism 
                emp->calculatePay(); 
                emp->displayPay(); 
                break; 
            } 
 
            case 2: { 
                SalariedEmployee s; 
                s.inputDetails(); 
                emp = &s; 
                emp->calculatePay(); 
                emp->displayPay(); 
                break; 
            } 
 
            case 3: { 
                ContractualEmployee c; 
                c.inputDetails(); 
                emp = &c; 
                emp->calculatePay(); 
                emp->displayPay(); 
                break; 
            } 
 
            case 4: 
                cout << "Exiting Payroll System. Goodbye!\n"; 
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
