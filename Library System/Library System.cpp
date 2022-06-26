// Library System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


//started project






bool menu() {
    cout << "\nLibray Menu:\n";
    cout << "1) Add book\n";
    cout << "2) Search books by prefix\n";
    cout << "3) Print who borrowed book by name\n";
    cout << "4) Print library by ID\n";
    cout << "5) Print library by name\n";
    cout << "6) Add user\n";
    cout << "7) User borrow book\n";
    cout << "8) User return book\n";
    cout << "9) Print users\n";
    cout << "10) Exit\n";
    cout << "\nPlease enter your menu choice [1 - 10]: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case(10):
        return false;
    }
}


int main()
{
    bool run = true;
    while (run)
        run = menu();
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
