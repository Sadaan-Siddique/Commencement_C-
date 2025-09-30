#include <iostream>
using namespace std;

int main()
{
    int num_1, num_2;
    char op;
    cout << "Enter first integer : ";
    cin >> num_1;
    cout << "Enter an operator ( + - * / % ) : ";
    cin >> op;
    cout << "Enter second integer : ";
    cin >> num_2;

    switch (op)
    {
    case '+':
        cout << "By adding : " << num_1 + num_2;
        break;

    case '-':
        cout << "By subtracting : " << num_1 - num_2;
        break;

    case '*':
        cout << "By multiplying : " << num_1 * num_2;
        break;

    case '/':
        if (num_2 == 0)
        {
            cout << "Undefined";
        }
        else
        {
            cout << "By dividing : " << num_1 / num_2;
            break;
        }
    case '%':
        cout << "Their remainder is : " << num_1 % num_2;
        break;
    }
    return 0;
}

// Task 1: Number Sign Checker

// 👉 Write a C++ program that takes a number as input and tells whether it’s positive, negative, or zero.
// (Use if–else)
int main()
{
    int num;
    cout << "Please enter a number : ";
    cin >> num;
    if (num > 0)
    {
        cout << "Number you entered is positive ";
    }
    else if (num == 0)
    {
        cout << "Number you entered is zero";
    }
    else
    {
        cout << "Number you entered is negative ";
    }
    cout << endl;
    cout << num;
    return 0;
}
