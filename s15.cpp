/*
Assignment Slip – 15
1. Create a Library Management System using file I/O to store and retrieve book records. 
Include command-line arguments to filter search results.
*/
#include <iostream.h> 
#include <fstream.h> 
#include <conio.h> 
#include <string.h> 
 
class Book { 
public: 
    int id; 
    char title[50]; 
    char author[50]; 
 
    void input() { 
        cout << "Enter Book ID: "; 
        cin >> id; 
        cout << "Enter Book Title: "; 
        cin >> title; 
        cout << "Enter Author Name: "; 
        cin >> author; 
    } 
 
    void display() { 
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl; 
    } 
}; 
 
void addBook() { 
    Book b; 
    ofstream outFile("books.dat", ios::binary | ios::app); 
    b.input(); 
    outFile.write((char*)&b, sizeof(b)); 
    outFile.close(); 
    cout << "Book added successfully!\n"; 
} 
 
void displayAllBooks() { 
    Book b; 
    ifstream inFile("books.dat", ios::binary); 
    cout << "\n----- Library Books -----\n"; 
    while(inFile.read((char*)&b, sizeof(b))) { 
        b.display(); 
    } 
    inFile.close(); 
} 
 
void searchBook() { 
    char searchTitle[50]; 
    cout << "Enter title to search: "; 
    cin >> searchTitle; 
 
    Book b; 
    ifstream inFile("books.dat", ios::binary); 
    int found = 0; 
    while(inFile.read((char*)&b, sizeof(b))) { 
        if(strcmp(b.title, searchTitle) == 0) { 
            cout << "Book Found:\n"; 
            b.display(); 
            found = 1; 
            break; 
        } 
    } 
    if(!found) 
        cout << "Book not found!\n"; 
 
    inFile.close(); 
} 
 
void main() { 
    clrscr(); 
    int choice; 
 
    do { 
        cout << "\n------ Library Management System ------\n"; 
        cout << "1. Add Book\n"; 
        cout << "2. Display All Books\n"; 
        cout << "3. Search Book by Title\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice) { 
            case 1: 
                addBook(); 
                break; 
            case 2: 
                displayAllBooks(); 
                break; 
            case 3: 
                searchBook(); 
                break; 
            case 4: 
                cout << "Exiting Library System. Goodbye!\n"; 
                break; 
            default: 
                cout << "Invalid choice! Try again.\n"; 
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
