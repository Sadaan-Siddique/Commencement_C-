#include <iostream>
#include <string>
using namespace std;

// Factorial Function
int main()
{
    int num = 0, i = 0;
    long long factorial = 1;

    cout << "Enter a number: ";
    cin >> num;

    for (int save = num; save != 0; i++)
    {
        save -= 1;
    }
    for (int save = num; i != 0; i--)
    {
        factorial *= save;
        save -= 1;
    }
    cout << endl
         << num << "! = " << factorial;
    return 0;
}

int main_3()
{
    string concat = "The number is: ", sentence = "Your name is: ", name = "";
    int num = 0;
    cout << "Wtite a number: ";
    cin >> num;
    cout << "Write your name: ";
    cin >> name;
    concat = "The number is: " + to_string(num);
    cout << endl
         << concat << endl
         << sentence.append(name);
    return 0;
}

// Quiz 1 Code

int main_1()
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
