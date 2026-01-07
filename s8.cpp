/*
Assignment Slip – 8
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
2. Create a C++ program to simulate a basic calculator supporting expression parsing using 
function overloading and inline functions
*/
#include <iostream.h> 
#include <conio.h> 
 
class Calculator { 
public: 
 
    inline int add(int a, int b) { 
        return a + b; 
    } 
 
    inline double add(double a, double b) { 
        return a + b; 
    } 
 
    
    inline int subtract(int a, int b) { 
        return a - b; 
    } 
 
 
    inline double subtract(double a, double b) { 
        return a - b; 
    } 
 
 
    inline int multiply(int a, int b) { 
        return a * b; 
    } 
 
 
    inline double multiply(double a, double b) { 
        return a * b; 
    } 
 
   
    inline float divide(int a, int b) { 
        if(b != 0) 
            return (float)a / b; 
        else { 
            cout << "Error! Division by zero." << endl; 
            return 0; 
        } 
    } 
 
    inline double divide(double a, double b) { 
        if(b != 0) 
            return a / b; 
        else { 
            cout << "Error! Division by zero." << endl; 
            return 0; 
        } 
    } 
}; 
 
void main() { 
    clrscr(); 
    Calculator calc; 
    int choice; 
     
    do { 
        cout << "\n------ Basic Calculator ------\n"; 
        cout << "1. Add\n"; 
        cout << "2. Subtract\n"; 
        cout << "3. Multiply\n"; 
        cout << "4. Divide\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        if(choice >=1 && choice <=4) { 
            char type; 
            cout << "Enter 'i' for integer or 'd' for double: "; 
            cin >> type; 
 
            if(type == 'i') { 
                int x, y; 
                cout << "Enter two integers: "; 
                cin >> x >> y; 
 
                switch(choice) { 
                    case 1: cout << "Result: " << calc.add(x, y); break; 
                    case 2: cout << "Result: " << calc.subtract(x, y); break; 
                    case 3: cout << "Result: " << calc.multiply(x, y); break; 
                    case 4: cout << "Result: " << calc.divide(x, y); break; 
                } 
            } else if(type == 'd') { 
                double x, y; 
                cout << "Enter two double numbers: "; 
                cin >> x >> y; 
 
                switch(choice) { 
                    case 1: cout << "Result: " << calc.add(x, y); break; 
                    case 2: cout << "Result: " << calc.subtract(x, y); break; 
                    case 3: cout << "Result: " << calc.multiply(x, y); break; 
                    case 4: cout << "Result: " << calc.divide(x, y); break; 
                } 
            } else { 
                cout << "Invalid type!" << endl; 
            } 
        } else if(choice == 5) { 
            cout << "Exiting Calculator. Goodbye!\n"; 
        } else { 
            cout << "Invalid choice! Try again.\n"; 
        } 
    } while(choice != 5); 
 
    getch();  
}