#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
public:
    int id;
    string name;
    string author;
    bool isIssued;
};

void loadBooks(vector<Book> &books)
{
    string line;
    ifstream MyFile("books.txt");
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

        // if (status == "0")
        //     b.isIssued = false;
        // else
        //     b.isIssued = true;
        b.isIssued = (status == "1");
        
        books.push_back(b);
    }
    MyFile.close();
}

void saveBooks(const vector<Book> &books)
{
    ofstream MyFile("books.txt");
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

int main()
{
    vector<Book> books;
    loadBooks(books);
    int choice;

    do
    {
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

        cout << "\nEnter your choice: ";
        cin >> choice;

        cout << "\nYou selected option: " << choice << endl
             << endl;
        if (choice == 1)
        {
            Book b1;
            cout << "Enter Book ID: ";
            cin >> b1.id;
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
        else if (choice == 2)
        {
            for (int i = 0; i < books.size(); i++)
            {
                cout << "Book ID: " << books[i].id << endl;
                cout << "Book Name: " << books[i].name << endl;
                cout << "Author: " << books[i].author << endl;
                if (books[i].isIssued)
                    cout << "Status: Issued" << endl;
                else
                    cout << "Status: Available" << endl;
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            int searchId;
            bool found = false;
            cout << "Enter Book ID: ";
            cin >> searchId;
            for (Book b : books)
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
        else if (choice == 4)
        {
            int searchId;
            bool found = false;
            cout << "Enter Book ID: ";
            cin >> searchId;
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

        else if (choice == 5)
        {
            bool found = false;
            int searchId;
            cout << "Enter book ID: ";
            cin >> searchId;
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

        else if (choice == 6)
        {
            bool found = false;
            int searchId;
            cout << "\nEnter Book ID: ";
            cin >> searchId;

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

        else if (choice == 7)
            cout
                << "Exiting..." << endl;
        else
            cout << "Invalid choice" << endl;

    } while (choice != 7);

    return 0;
}