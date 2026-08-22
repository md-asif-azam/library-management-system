#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    vector<Book> books;
    loadBooks(books);
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        choice = getValidInt();

        cout << "\nYou selected option: " << choice << endl
             << endl;
        if (choice == 1)
            addBook(books);
        else if (choice == 2)
            displayBooks(books);
        else if (choice == 3)
            searchBook(books);
        else if (choice == 4)
            issueBook(books);
        else if (choice == 5)
            returnBook(books);
        else if (choice == 6)
            removeBook(books);
        else if (choice == 7)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid choice" << endl;
    } while (choice != 7);

    return 0;
}