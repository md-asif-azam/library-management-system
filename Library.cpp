#include "Library.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "=================================\n";
        cout << "      LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=================================\n";

        cout << "\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Remove Book\n";
        cout << "7. Exit\n";
}

int getValidInt()
{
    int num;
    while (true)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number: " << endl;
        }
        else
            return num;
    }
}

void saveBooks(const vector<Book> &books)
{
    ofstream MyFile("books.txt");
    if(!MyFile) {
        cout << "File couldn't be opened" << endl;
        return;
    }
    for (const auto &b : books)
    {
        MyFile << b.id << "|" << b.name << "|" << b.author << "|";
        if (b.isIssued)
            MyFile << "1";
        else
            MyFile << "0";
        MyFile << endl;
    }
    MyFile.close();
}

void addBook(vector<Book> &books)
{
    bool dup = false;
    Book b1;
    cout << "Enter Book ID: ";
    b1.id = getValidInt();
    for (const auto &b : books)
    {
        if (b.id == b1.id)
        {
            cout << "Book ID already exists!" << endl;
            dup = true;
            break;
        }
    }
    if (!dup)
    {
        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, b1.name);
        cout << "Enter Book Author: ";
        getline(cin, b1.author);
        cout << endl;
        b1.isIssued = false;
        books.push_back(b1);
        saveBooks(books);
        cout << "Book added successfully!" << endl;
    }
}

void displayBooks(const vector<Book> &books)
{
    if (books.empty())
    {
        cout << "No books available." << endl;
        return;
    }
    for (const auto &b : books)
    {
        cout << "Book ID: " << b.id << endl;
        cout << "Book Name: " << b.name << endl;
        cout << "Author: " << b.author << endl;
        if (b.isIssued)
            cout << "Status: Issued" << endl;
        else
            cout << "Status: Available" << endl;
        cout << endl;
    }
}

void searchBook(const vector<Book> &books)
{
    int searchId;
    bool found = false;
    cout << "Enter Book ID: ";
    searchId = getValidInt();
    for (const auto &b : books)
    {
        if (b.id == searchId)
        {
            cout << "Book found!" << endl
                 << endl;
            cout << "Book ID: " << b.id << endl;
            cout << "Book Name: " << b.name << endl;
            cout << "Author: " << b.author << endl;
            found = true;
            break;
        }
    }
    if (found == false)
        cout << "Book not found" << endl;
}

void issueBook(vector<Book> &books)
{
    int searchId;
    bool found = false;
    cout << "Enter Book ID: ";
    searchId = getValidInt();
    for (auto &b : books)
    {
        if (b.id == searchId)
        {
            found = true;
            if (!b.isIssued)
            {
                cout << "Book issued successfully!" << endl
                     << endl;
                b.isIssued = true;
                saveBooks(books);
                break;
            }
            else
            {
                cout << "Book is already issued" << endl
                     << endl;
                break;
            }
        }
    }
    if (!found)
        cout << "\nBook not found" << endl;
}

void returnBook(vector<Book> &books)
{
    bool found = false;
    int searchId;
    cout << "Enter book ID: ";
    searchId = getValidInt();
    for (auto &b : books)
    {
        if (b.id == searchId)
        {
            found = true;
            if (!b.isIssued)
            {
                cout << "Book is not currently issued. " << endl;
                break;
            }
            else
            {
                b.isIssued = false;
                cout << "Book returned successfully!" << endl;
                saveBooks(books);
                break;
            }
        }
    }
    if (!found)
        cout << "Book not found." << endl;
}

void removeBook(vector<Book> &books)
{
    bool found = false;
    int searchId;
    cout << "\nEnter Book ID: ";
    searchId = getValidInt();

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == searchId)
        {
            found = true;
            books.erase(books.begin() + i);
            cout << "\nBook removed successfully!" << endl;
            saveBooks(books);
            break;
        }
    }
    if (found == false)
        cout << "\nBook not found." << endl;
}

void loadBooks(vector<Book> &books)
{
    string line;
    ifstream MyFile("books.txt");
    if(!MyFile) {
        cout << "No existing library data found. Starting with an empty library." << endl;
        return;
    }
    while (getline(MyFile, line))
    {
        Book b;
        string id;
        string name;
        string author;
        string status;

        stringstream ss(line);
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, author, '|');
        getline(ss, status, '|');

        b.id = stoi(id);
        b.name = name;
        b.author = author;
        b.isIssued = (status == "1");

        books.push_back(b);
    }
    MyFile.close();
}