// Library System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;


//started project

const int MAX_BOOKS = 10;
const int MAX_USERS = 10;
int totalUsers = 0;
int totalBooks = 0;

struct book {
    int id = -1;
    string name = "";
    int total_quantity = 0;
    int total_borrowed = 0;

    void add_book() {
        cout << "Please enter the id, name and total quantity of the new book: ";
        cin >> id >> name >> total_quantity;
    }

    int return_book_ID() {
        return id;
    }

    void print_book() {
        cout << "ID: " << id << ". Name: " << name << ". Total quantity: " << total_quantity << ". Total borrowed: " << total_borrowed << "\n";
    }
};

struct users {
    string name = "";
    int id = -1;
    int borrow_books_id[MAX_BOOKS];
    int amountBorrowed = 0;

    void addUser() {
        cout << "Please enter the name and id of the new user: ";
        cin >> name >> id;
    }

    void printUser() {
        cout << "User: " << name << ". ID: " << id << ". Borrowed book ID's: ";
        for (int i = 0; i < MAX_BOOKS; i++) {
            if (borrow_books_id[i] <= 0) {
                cout << "\n";
                return;
            }
            else {
                cout << borrow_books_id[i] << " ";
            }

        }
    }

    
};

struct library_system {
    users libraryUsers[MAX_USERS];
    book libraryBooks[MAX_BOOKS];
    bool run() {
        bool run = true;
        while (run)
            run = menu();
        return 0;
    }

    void print_library_by_id() {        
        int previousNum = 0;
        for (int i = 0; i < totalBooks; i++) {
            int lowestId = libraryBooks[i].return_book_ID();
            int lowestIdPosition = i;
            for (int j = 0; j < totalBooks+1; j++) {
                int IDCheck = libraryBooks[j].return_book_ID();
                cout << IDCheck << endl;
                cout << "Previous num" << previousNum << endl;
                if (IDCheck < lowestId && IDCheck > previousNum) {
                    lowestId = IDCheck;
                    lowestIdPosition = j;
                }
            }
            libraryBooks[lowestIdPosition].print_book();
            previousNum = libraryBooks[lowestIdPosition].return_book_ID();

        }
    }

    bool menu() {
        cout << "\nLibrary Menu:\n";
        cout << "1) add_book\n";
        cout << "2) search books by prefix\n";
        cout << "3) print who borrow book by name\n";
        cout << "4) print library by id\n";
        cout << "5) print library by name\n";
        cout << "6) add user\n";
        cout << "7) user borrow book\n";
        cout << "8) user return book\n";
        cout << "9) print users\n";
        cout << "10) exit\n\n";
        cout << "Enter your menu choice [1 - 10]: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case(1): {
            libraryBooks[totalBooks++].add_book();
            break;
        }
        case(2): {
            break;
        }
        case(3): {
            break;
        }
        case(4): {
            print_library_by_id();
            break;
        }
        case(5): {
            break;
        }
        case(6): {
            libraryUsers[totalUsers++].addUser();
            break;
        }
        case(7): {
            break;
        }
        case(8): {
            break;
        }
        case(9): {
            for (int i = 0; i < totalUsers; i++) {
                libraryUsers[i].printUser();
            }
            break;
        }
        case(10): {
            return false;
        }
        default: {
            cout << "Sorry can you try that again please\n";
        }

        }
        
    }
};




int main()
{
    library_system library;
    library.run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
