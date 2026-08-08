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
};

int main()
{
    vector<Book> books;
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

        cout << "\nYou selected option: " << choice << endl;
        if (choice == 1)
        {
            Book b1;
            cout << "Add Book selected" << endl;
            cout << "Enter Book ID: ";
            cin >> b1.id;
            cin.ignore();
            cout << "Enter Book Name: ";
            getline(cin, b1.name);
            cout << "Enter Book Author: ";
            getline(cin, b1.author);
            cout << endl;
            books.push_back(b1);
            cout << "Book added successfully!" << endl;
        }
        else if (choice == 2) {
            for(int i=0; i<books.size(); i++) {
                cout << "Book ID: " << books[i].id << endl;
                cout << "Book Name: " << books[i].name << endl;
                cout << "Author: " << books[i].author << endl;
                cout << endl;
            }
        }
        else if (choice == 3) {
            int searchId;
            bool found = false;
            cout << "Enter Book ID: ";
            cin >> searchId;
            for(Book b : books) {
                if(b.id == searchId) {
                    cout << "Book found!"<< endl << endl;
                    cout << "Book ID: " << b.id << endl;
                    cout << "Book Name: " << b.name << endl;
                    cout << "Author: " << b.author << endl;
                    found = true;
                    break;
                }
            }
            if(found == false)
                cout << "Book not found" << endl;
        }
        else if (choice == 4)
            cout
                << "Issue Book selected" << endl;
        else if (choice == 5)
            cout
                << "Return Book selected" << endl;
        else if (choice == 6)
            cout
                << "Remove Book selected" << endl;
        else if (choice == 7)
            cout
                << "Exiting..." << endl;
        else
            cout << "Invalid choice" << endl;

    } while (choice != 7);

    return 0;
}