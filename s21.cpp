/*
Assignment Slip – 21
1. Write a menu-driven program using control structures to simulate a student grading 
system with support for conditional and looping constructs.
*/
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
/*
2. Design a C++ program that logs errors into a file and uses exception handling to manage 
file not found or access denied issues
*/
#include <iostream.h> 
#include <fstream.h> 
#include <conio.h> 
#include <stdlib.h> 
 
void logError(const char* message) { 
    ofstream outFile; 
    try { 
        outFile.open("error_log.txt", ios::app); 
        if(!outFile) 
            throw "Unable to open error log file!"; 
        outFile << message << endl; 
        outFile.close(); 
        cout << "Error logged successfully.\n"; 
    } catch(const char* msg) { 
        cout << "Exception: " << msg << endl; 
    } 
} 
 
void main() { 
    clrscr(); 
 
    int choice; 
    do { 
        cout << "\n------ Error Logging System ------\n"; 
        cout << "1. Simulate Error\n"; 
        cout << "2. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: { 
                try { 
                    // Simulate an error (e.g., divide by zero) 
                    int a = 10, b; 
                    cout << "Enter divisor: "; 
                    cin >> b; 
                    if(b == 0) 
                        throw "Division by zero error!"; 
                    int c = a / b; 
                    cout << "Result: " << c << endl; 
                } catch(const char* errMsg) { 
                    cout << "Caught Exception: " << errMsg << endl; 
                    logError(errMsg); // Log the error to file 
                } 
                break; 
            } 
 
            case 2: 
                cout << "Exiting Error Logging System. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
    } while(choice != 2); 
 
    getch(); 
} 
