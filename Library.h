#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

using namespace std;

void displayMenu();
int getValidInt();

void saveBooks(const vector<Book> &books);
void loadBooks(vector<Book> &books);

void addBook(vector<Book> &books);
void displayBooks(const vector<Book> &books);
void searchBook(const vector<Book> &books);
void issueBook(vector<Book> &books);
void returnBook(vector<Book> &books);
void removeBook(vector<Book> &books);

#endif