/*
Assignment Slip – 14
1. Design a mini ATM interface that simulates balance inquiry, deposit, and withdrawal 
using encapsulation and basic C++ constructs.
*/
#include <iostream.h> 
#include <conio.h> 
 
class ATM { 
private: 
    double balance;   
 
public: 
    ATM() { 
        balance = 0.0; 
    } 
 
    void checkBalance() { 
        cout << "Your current balance is: Rs. " << balance << endl; 
    } 
 
    void deposit() { 
        double amount; 
        cout << "Enter amount to deposit: Rs. "; 
        cin >> amount; 
        if(amount > 0) { 
            balance += amount; 
            cout << "Amount deposited successfully!" << endl; 
        } else { 
            cout << "Invalid amount!" << endl; 
        } 
    } 
 
    void withdraw() { 
        double amount; 
        cout << "Enter amount to withdraw: Rs. "; 
        cin >> amount; 
        if(amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "Please collect your cash." << endl; 
        } else { 
            cout << "Insufficient balance or invalid amount!" << endl; 
        } 
    } 
}; 
 
void main() { 
    clrscr();   
    ATM myATM; 
    int choice; 
 
    do { 
        cout << "\n------ Mini ATM Interface ------\n"; 
        cout << "1. Balance Inquiry\n"; 
        cout << "2. Deposit\n"; 
        cout << "3. Withdraw\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                myATM.checkBalance(); 
                break; 
            case 2: 
                myATM.deposit(); 
                break; 
            case 3: 
                myATM.withdraw(); 
                break; 
            case 4: 
                cout << "Thank you for using the ATM. Goodbye!\n"; 
                break; 
            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } while(choice != 4); 
 
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