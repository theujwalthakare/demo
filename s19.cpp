/*
*Assignment Slip – 19
1. Design a payroll system using run-time polymorphism (abstract classes + pure virtual 
functions) for different employee types (hourly, salaried, contractual).
*/
 { 
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
2. Create a template-based sorting class that works with multiple data types and 
incorporates exception handling for invalid inputs
*/
#include <iostream.h> 
#include <conio.h> 
#include <stdlib.h> 
 
template <class T> 
class Sorter { 
private: 
    T arr[50]; 
    int size; 
public: 
    void input() { 
        cout << "Enter number of elements (max 50): "; 
        cin >> size; 
        if(size <= 0 || size > 50) { 
            throw "Invalid size! Must be between 1 and 50."; 
        } 
 
        cout << "Enter " << size << " elements:\n"; 
        for(int i = 0; i < size; i++) { 
            cin >> arr[i]; 
        } 
    } 
 
    void bubbleSort() { 
        for(int i = 0; i < size-1; i++) { 
            for(int j = 0; j < size-i-1; j++) { 
                if(arr[j] > arr[j+1]) { 
                    T temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
            } 
        } 
    } 
 
    void display() { 
        cout << "Sorted elements: "; 
        for(int i = 0; i < size; i++) 
            cout << arr[i] << " "; 
        cout << endl; 
    } 
}; 
 
void main() { 
    clrscr(); 
 
    int choice; 
    do { 
        cout << "\n------ Template Sorting Menu ------\n"; 
        cout << "1. Sort Integers\n"; 
        cout << "2. Sort Floating Point Numbers\n"; 
        cout << "3. Sort Characters\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        try { 
            switch(choice) { 
                case 1: { 
                    Sorter<int> s; 
                    s.input(); 
                    s.bubbleSort(); 
                    s.display(); 
                    break; 
                } 
                case 2: { 
                    Sorter<float> s; 
                    s.input(); 
                    s.bubbleSort(); 
                    s.display(); 
                    break; 
                } 
                case 3: { 
                    Sorter<char> s; 
                    s.input(); 
                    s.bubbleSort(); 
                    s.display(); 
                    break; 
                } 
                case 4: 
                    cout << "Exiting program. Goodbye!\n"; 
                    break; 
                default: 
                    cout << "Invalid choice! Try again.\n"; 
            } 
        } catch(char const* msg) { 
            cout << "Error: " << msg << endl; 
        } 
 
    } while(choice != 4); 
 
    getch();  
} 

