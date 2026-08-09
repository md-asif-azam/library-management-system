#include <iostream>
using namespace std;
int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input!" << endl;
    }
    else
    {
        cout << "You entered: " << number << endl;
    }
}