// Task 01
// Write a program that takes an integer n as input and prints a diamond of numbers using nested for loops.
// E.g :
//   1
//  1 2
// 1 2 3
//  1 2
//   1

#include <iostream>
using namespace std;

int main()
{
    // Decalaring Variables
    int i = 1, length = 0;

    // Taking Input
    cout << "Enter the length of columns of diamond you want :";
    cin >> length;

    // It'll print first half of diamond in an ascending order
    for (; i < length; i++)
    {
        for (int spacing = length; spacing >= i; spacing--)
        {
            cout << " ";
        }
        for (int col = 1; col <= i; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    // It'll print second half of diamond in a descending order
    for (; i > 0; i--)
    {
        for (int spacing = length; spacing >= i; spacing--)
        {
            cout << " ";
        }
        for (int col = 1; col <= i; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}