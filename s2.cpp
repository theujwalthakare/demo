// Assignment Slip – 2
// 1. Write a menu-driven program using control structures to simulate a student grading 
// system with support for conditional and looping constructs.
#include <iostream.h> 
#include <conio.h> 
 
void main() { 
    clrscr();  
 
    int choice; 
    do { 
        cout << "\n------ Student Grading System ------\n"; 
        cout << "1. Enter student marks and get grade\n"; 
        cout << "2. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: { 
                char studentName[50]; 
                int marks; 
 
                cout << "Enter student name: "; 
                cin >> studentName; 
 
                cout << "Enter marks (0-100): "; 
                cin >> marks; 
 
                if(marks < 0 || marks > 100) { 
                    cout << "Invalid marks! Please enter between 0 and 100.\n"; 
                } else { 
                    cout << "\nStudent: " << studentName << endl; 
                    cout << "Marks: " << marks << endl; 
 
                     
                    if(marks >= 90) 
                        cout << "Grade: A+\n"; 
                    else if(marks >= 80) 
                        cout << "Grade: A\n"; 
                    else if(marks >= 70) 
                        cout << "Grade: B+\n"; 
                    else if(marks >= 60) 
                        cout << "Grade: B\n"; 
                    else if(marks >= 50) 
                        cout << "Grade: C\n"; 
                    else 
                        cout << "Grade: F (Fail)\n"; 
                } 
                break; 
            } 
 
            case 2: 
                cout << "Exiting Student Grading System. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
 
    } while(choice != 2);  
 
    getch();   
}
// 2. Implement a class for a Complex Number, overload the +, -, and * operators, and manage 
// memory using dynamic allocation
#include <iostream.h> 
#include <conio.h> 
#include <stdlib.h>  
 
class Complex { 
private: 
    double real; 
    double imag; 
 
public: 
     
    Complex(double r = 0, double i = 0) { 
        real = r; 
        imag = i; 
    } 
 
    
    void input() { 
        cout << "Enter real part: "; 
        cin >> real; 
        cout << "Enter imaginary part: "; 
        cin >> imag; 
    } 
 
     
    void display() { 
        cout << real; 
        if(imag >= 0) 
            cout << " + " << imag << "i" << endl; 
        else 
            cout << " - " << -imag << "i" << endl; 
    } 
 
    
    Complex operator + (Complex c) { 
        return Complex(real + c.real, imag + c.imag); 
    } 
 
    Complex operator - (Complex c) { 
        return Complex(real - c.real, imag - c.imag); 
    } 
 
    Complex operator * (Complex c) { 
        double r = (real * c.real - imag * c.imag); 
        double i = (real * c.imag + imag * c.real); 
        return Complex(r, i); 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    int choice; 
    Complex *c1 = new Complex();   
    Complex *c2 = new Complex(); 
    Complex result; 
 
    do { 
        cout << "\n------ Complex Number Calculator ------\n"; 
        cout << "1. Input Complex Numbers\n"; 
        cout << "2. Add\n"; 
        cout << "3. Subtract\n"; 
        cout << "4. Multiply\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                cout << "Enter first complex number:\n"; 
                c1->input(); 
                cout << "Enter second complex number:\n"; 
                c2->input(); 
                break; 
 
            case 2: 
                result = *c1 + *c2; 
                cout << "Result of addition: "; 
                result.display(); 
                break; 
 
            case 3: 
                result = *c1 - *c2; 
                cout << "Result of subtraction: "; 
                result.display(); 
                break; 
 
            case 4: 
                result = *c1 * *c2; 
                cout << "Result of multiplication: "; 
                result.display(); 
                break; 
 
            case 5: 
                cout << "Exiting program. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
    } while(choice != 5); 
 
     
    delete c1; 
    delete c2; 
 
    getch();   
}