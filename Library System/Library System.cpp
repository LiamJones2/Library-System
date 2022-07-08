// Library System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;


//Completed project

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

    int borrow_book() {
        if (total_borrowed < total_quantity) {
            total_borrowed++;
            return 0;
        }
        return -1;

    }

    void return_book() {
        total_borrowed--;
    }



    int return_book_ID() {
        return id;
    }

    string return_book_name() {
        return name;
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

    int return_user_id() {
        return id;
    }

    void borrowed_book(int IDOfBook) {
        borrow_books_id[amountBorrowed++] = IDOfBook;
    }

    int return_book_under_user(int IDOfBook) {
        int bookPositionInArray;
        if (amountBorrowed == 0) {
            return -1;
        }
        for (int i = 0; i < amountBorrowed; i++) {
            cout << borrow_books_id[i] << IDOfBook << endl;
            if (borrow_books_id[i] == IDOfBook) {
                bookPositionInArray = i;
                break;
            }
            if (i == amountBorrowed - 1)
                return -1;
        }
        for (int i = bookPositionInArray; i < amountBorrowed-1; i++) {
            borrow_books_id[i] = borrow_books_id[i + 1];
        }
        amountBorrowed--;
        return 1;
    }

    void printUser() {
        cout << "User: " << name << ". ID: " << id << ". Borrowed book ID's: ";
        for (int i = 0; i < amountBorrowed; i++) {           
            cout << borrow_books_id[i] << " ";           
        }
        cout << "\n";
    }

    void check_if_user_borrowed_book(int IDOfBook) {
        for (int i = 0; i < amountBorrowed; i++) {
            if (borrow_books_id[i] == IDOfBook)
                printUser();
        }
    }

    
};

users libraryUsers[MAX_USERS];
book libraryBooks[MAX_BOOKS];

bool run() {
    bool run = true;
    while (run)
        run = menu();
    return 0;
}

void search_books_by_prefix() {
    string prefixWord;
    cout << "Please enter the word you would like to search for\n";
    cin >> prefixWord;
    for (int i = 0; i < totalBooks; i++) {
        string wordToCheck = libraryBooks[i].return_book_name();
        int count = 0;
        for (int j = 0; j < prefixWord.length(); j++) {
            if (wordToCheck[j] == prefixWord[j]) {
                count++;
            }
        }
        if (count++ == prefixWord.length())
            libraryBooks[i].print_book();
    }
}

void print_who_borrowed_book_by_name() {
    int bookIDToCheck;
    cout << "Please enter the ID of the book you want to check who borrowed\n";
    cin >> bookIDToCheck;
    cout << "List of people who borrowed that book\n";
    for (int i = 0; i < totalUsers; i++) {
        libraryUsers[i].check_if_user_borrowed_book(bookIDToCheck);
    }
}

void print_library_by_id() {
    int previousNum = 0;
    int lowestNum = 10000000;
    int IDCheck;
    int lowestNumPosition = 0;
    for (int i = 0; i < totalBooks; i++) {
        lowestNum = 10000000;            
        for (int j = 0; j < totalBooks; j++) {
            IDCheck = libraryBooks[j].return_book_ID();
            if (IDCheck < lowestNum && IDCheck > previousNum) {
                lowestNum = IDCheck;
                lowestNumPosition = j;
            }
        }
        previousNum = lowestNum;
        libraryBooks[lowestNumPosition].print_book();
    }
}

void print_library_by_name() {
    string previousWord = "";
    string smallestWord = "zzzzzzzzzzzzzzzzz";
    string NameCheck;
    int smallestNamePosition = 0;
    for (int i = 0; i < totalBooks; i++) {
        smallestWord = 10000000;
        for (int j = 0; j < totalBooks; j++) {
            NameCheck = libraryBooks[j].return_book_name();
            if (NameCheck < smallestWord && NameCheck > previousWord) {
                smallestWord = NameCheck;
                smallestNamePosition = j;
            }
        }
        previousWord = smallestWord;
        libraryBooks[smallestNamePosition].print_book();
    }
}

int check_if_user_exists() {
    int IDCheck;
    cout << "Please enter the ID of the user: ";
    cin >> IDCheck;
    int IDOfUser = 0;
    for (int i = 0; i < totalUsers; i++) {
        if (libraryUsers[i].return_user_id() == IDCheck) {
            IDOfUser = libraryUsers[i].return_user_id();
            return i;
        }
    }
    return -1;
}

int check_if_book_exists() {
    int IDCheck;
    cout << "Please enter the ID of the book: ";
    cin >> IDCheck;
    int IDOfBook = 0;
    for (int i = 0; i < totalBooks; i++) {
        if (libraryBooks[i].return_book_ID() == IDCheck) {
            IDOfBook = libraryBooks[i].return_book_ID();
            return i;
        }
    }
    return -1;
}



void user_borrow_book() {
    int IDOfUserPosition = check_if_user_exists();
    if (IDOfUserPosition == -1) {
        cout << "Unfortunately we could not find that user on the system using that ID\n";
        return;
    }
    int bookPosition = check_if_book_exists();
    int checkStockOfBook = libraryBooks[bookPosition].borrow_book();
    if (checkStockOfBook == -1) {
        cout << "Unfortunately there is no stock left of that book\n";
        return;
    }
    int IDOfBook = libraryBooks[bookPosition].return_book_ID();
    libraryUsers[IDOfUserPosition].borrowed_book(IDOfBook);
    cout << "Book borrowing has been registered on the system\n";
            
}

        

void user_return_book() {
    int IDOfUserPosition = check_if_user_exists();
    if (IDOfUserPosition == -1) {
        cout << "Unfortunately we could not find that user on the system using that ID\n";
        return;
    }
    int bookPosition = check_if_book_exists();
    int IDOfBook = libraryBooks[bookPosition].return_book_ID();
    int returnedAnswer = libraryUsers[IDOfUserPosition].return_book_under_user(IDOfBook);
    if (returnedAnswer == -1) {
        cout << "Sorry but that user has not borrowed that book\n";
        return;
    }
    libraryBooks[IDOfUserPosition].return_book();
    cout << "Book has been returned\n";
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
        if (totalBooks < MAX_BOOKS) {
            libraryBooks[totalBooks++].add_book();
        }
        else {
            cout << "Unfortunately we have too many books and can't add another one\n";
        }
        break;
        }
    case(2): {
        search_books_by_prefix();
        break;
    }
    case(3): {
        print_who_borrowed_book_by_name();
        break;
    }
    case(4): {
        print_library_by_id();
        break;
    }
    case(5): {
        print_library_by_name();
        break;
    }
    case(6): {
        if (totalUsers < MAX_USERS) {
            libraryUsers[totalUsers++].addUser();
        }
        else {
            cout << "Unfortunately we have too many users and can't add another one\n";
        }
        break;
    }
    case(7): {
        user_borrow_book();
        break;
    }
    case(8): {
        user_return_book();
        break;
    }
    case(9): {
        for (int i = 0; i < totalUsers; i++) {
            libraryUsers[i].printUser();
            cout << "\n";
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





int main()
{
    run();
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
