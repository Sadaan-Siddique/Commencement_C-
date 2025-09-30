#include <iostream>
using namespace std;

// Quiz 1 Code

int main()
{



    int A = 0;
    cout << "Write your amount in Rupees : Rs.";
    cin >> A;

    if (A <= 0)
    {
        cout << "Amount must be a positive integer." << endl;
        return 0;
    }

    cout << "\nYour amount equivalent to currency notes is : " << endl;

    int rem = A; // start with full amount

    cout << "5000 : " << rem / 5000 << endl;
    rem = rem % 5000;

    cout << "1000 : " << rem / 1000 << endl;
    rem = rem % 1000;

    cout << "500  : " << rem / 500 << endl;
    rem = rem % 500;

    cout << "100  : " << rem / 100 << endl;
    rem = rem % 100;

    cout << "50   : " << rem / 50 << endl;
    rem = rem % 50;

    cout << "10   : " << rem / 10 << endl;
    rem = rem % 10;

    cout << "5    : " << rem / 5 << endl;
    rem = rem % 5;

    cout << "2    : " << rem / 2 << endl;
    rem = rem % 2;

    cout << "1    : " << rem / 1 << endl;

    return 0;














    // int A = 0;
    // cout << "Write your amount in Rupees : Rs.";
    // cin >> A;
    // if (A == 0 || A < 0)
    // {
    //     cout << "Amount must be a positive integer." << endl;
    //     return 0;
    // }

    // cout << "Your amount equivalent to currency notes is : " << endl;
    // cout << "5000 : " << A / 5000 << endl;
    // cout << "1000 : " << (A % 5000) / 1000 << endl;
    // cout << "500 : " << ((A % 5000) % 1000) / 500 << endl;
    // cout << "100 : " << (((A % 5000) % 1000) % 500) / 100 << endl;
    // cout << "50 : " << ((((A % 5000) % 1000) % 500) % 100) / 50 << endl;
    // cout << "10 : " << (((((A % 5000) % 1000) % 500) % 100) % 50) / 10 << endl;
    // cout << "5 : " << ((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) / 5 << endl;
    // cout << "2 : " << (((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) % 5) / 2 << endl;
    // cout << "1 : " << ((((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) % 5) % 2) / 1 << endl;
    // return 0;






}












// Task 2: Simple Calculator

// 👉 Ask the user to input:

// Two numbers

// An operator (+ , - , * , /)

// Then, using a switch statement, perform the calculation and print the result.
int main_2()
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
            break;
        }
        else
        {
            cout << "By dividing : " << (static_cast<double>(num_1) / num_2);
            break;
        }
    case '%':
        if (num_2 == 0)
            cout << "Undefined (division b zero)";
        else
            cout << "Their remainder is : " << num_1 % num_2;
        break;
    default:
        cout << "Please type an operator among ' + - * / % '";
    }
    return 0;
}



















// Task 1: Number Sign Checker

// 👉 Write a C++ program that takes a number as input and tells whether it’s positive, negative, or zero.
// (Use if–else)
int main_3()
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
