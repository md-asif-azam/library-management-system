#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
public:
    int id;
    string name;
    string author;
    bool isIssued;
};

#endif