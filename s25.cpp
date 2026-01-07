/*
Assignment Slip – 25
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
2. Create a pointer-based implementation of a class where objects are dynamically created 
and manipulated using this pointer and constructors/destructors
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
