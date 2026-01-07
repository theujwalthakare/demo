/*
*Assignment Slip – 20
1. Develop a custom vector class using C++ STL and templates, with member functions to 
perform insert, delete, and search operations.
*/
#include <iostream.h> 
#include <conio.h> 
 
template <class T> 
class MyVector { 
private: 
    T arr[50];      
    int size;       
 
public: 
    MyVector() { 
        size = 0; 
    } 
 
    
    void insert(T value) { 
        if(size >= 50) { 
            cout << "Vector is full!\n"; 
            return; 
        } 
        arr[size] = value; 
        size++; 
        cout << "Element inserted successfully.\n"; 
    } 
 
   
    void deleteElement(T value) { 
        int i, pos = -1; 
        for(i = 0; i < size; i++) { 
            if(arr[i] == value) { 
                pos = i; 
                break; 
            } 
        } 
        if(pos == -1) { 
            cout << "Element not found!\n"; 
            return; 
        } 
        for(i = pos; i < size - 1; i++) { 
            arr[i] = arr[i + 1];  // Shift elements 
        } 
        size--; 
        cout << "Element deleted successfully.\n"; 
    } 
 
    
    void search(T value) { 
        for(int i = 0; i < size; i++) { 
            if(arr[i] == value) { 
                cout << "Element found at position: " << i + 1 << endl; 
                return; 
            } 
        } 
        cout << "Element not found!\n"; 
    } 
 
     
    void display() { 
        if(size == 0) { 
            cout << "Vector is empty.\n"; 
            return; 
        } 
        cout << "Elements in vector: "; 
        for(int i = 0; i < size; i++) 
            cout << arr[i] << " "; 
        cout << endl; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    MyVector<int> vec;  
    int choice, value; 
 
    do { 
        cout << "\n------ Custom Vector Menu ------\n"; 
        cout << "1. Insert Element\n"; 
        cout << "2. Delete Element\n"; 
        cout << "3. Search Element\n"; 
        cout << "4. Display Vector\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                vec.insert(value); 
                break; 
 
            case 2: 
                cout << "Enter value to delete: "; 
                cin >> value; 
                vec.deleteElement(value); 
                break; 
 
            case 3: 
                cout << "Enter value to search: "; 
                cin >> value; 
                vec.search(value); 
                break; 
 
            case 4: 
                vec.display(); 
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

/*
2. Write a C++ program to simulate a bank transaction system that throws and handles 
multiple exceptions (e.g., insufficient funds, invalid account)
*/
#include <iostream.h> 
#include <conio.h> 
#include <string.h> 
 
class BankAccount { 
private: 
    int accountNo; 
    char name[50]; 
    float balance; 
 
public: 
    BankAccount(int acc = 0, const char* n = "", float bal = 0.0) { 
        accountNo = acc; 
        strcpy(name, n); 
        balance = bal; 
    } 
 
    int getAccountNo() { 
        return accountNo; 
    } 
 
    void deposit(float amount) { 
        if(amount <= 0) 
            throw "Invalid deposit amount!"; 
        balance += amount; 
        cout << "Amount deposited successfully. Current Balance: Rs. " << balance << endl; 
    } 
 
    void withdraw(float amount) { 
        if(amount <= 0) 
            throw "Invalid withdrawal amount!"; 
        if(amount > balance) 
            throw "Insufficient funds!"; 
        balance -= amount; 
        cout << "Amount withdrawn successfully. Current Balance: Rs. " << balance << endl; 
    } 
 
    void display() { 
        cout << "Account No: " << accountNo  
             << ", Name: " << name  
             << ", Balance: Rs. " << balance << endl; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    BankAccount accounts[5] = { 
        BankAccount(101, "Alice", 5000), 
        BankAccount(102, "Bob", 3000), 
        BankAccount(103, "Charlie", 7000), 
        BankAccount(104, "David", 2000), 
        BankAccount(105, "Eve", 10000) 
    }; 
 
    int choice; 
    do { 
        cout << "\n------ Bank Transaction System ------\n"; 
        cout << "1. Deposit\n"; 
        cout << "2. Withdraw\n"; 
        cout << "3. Display Account\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: { 
                int accNo, i; 
                float amt; 
                cout << "Enter Account Number: "; 
                cin >> accNo; 
             
                for(i = 0; i < 5; i++) { 
                    if(accounts[i].getAccountNo() == accNo) 
                        break; 
                } 
                try { 
                    if(i == 5) throw "Invalid account number!"; 
                    cout << "Enter amount to deposit: "; 
                    cin >> amt; 
                    accounts[i].deposit(amt); 
                } catch(const char* msg) { 
                    cout << "Error: " << msg << endl; 
                } 
                break; 
            } 
 
            case 2: { 
                int accNo, i; 
                float amt; 
                cout << "Enter Account Number: "; 
                cin >> accNo; 
                
                for(i = 0; i < 5; i++) { 
                    if(accounts[i].getAccountNo() == accNo) 
                        break; 
                } 
                try { 
                    if(i == 5) throw "Invalid account number!"; 
                    cout << "Enter amount to withdraw: "; 
                    cin >> amt; 
                    accounts[i].withdraw(amt); 
                } catch(const char* msg) { 
                    cout << "Error: " << msg << endl; 
                } 
                break; 
            } 
 
            case 3: { 
                int accNo, i; 
                cout << "Enter Account Number: "; 
                cin >> accNo; 
                 
                for(i = 0; i < 5; i++) { 
                    if(accounts[i].getAccountNo() == accNo) 
                        break; 
                } 
                try { 
                    if(i == 5) throw "Invalid account number!"; 
                    accounts[i].display(); 
                } catch(const char* msg) { 
                    cout << "Error: " << msg << endl; 
                } 
                break; 
            } 
 
            case 4: 
                cout << "Exiting Bank System. Goodbye!\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
 
    } while(choice != 4); 
 
    getch();   
}
