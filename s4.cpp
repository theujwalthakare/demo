/*
Assignment Slip – 4
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

