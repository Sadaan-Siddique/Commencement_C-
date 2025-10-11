// TASK_02 
// Write a program that takes input an intger and then output both the individual digits of the input number and the sum of the digits.
// For a negative number, use abs(number) => number will become positive.

#include <iostream>
#include <cmath> // for pow
#include <string>
using namespace std;

int main()
{
    // Declaring Varibales
    int num = 0, sum = 0, remainder = 0, quotient = 1, save = 0, i;
    long long power = 1;

    cout << "Enter a number: ";
    cin >> num;

    // Checking if integer is negative or not.
    if (num < 0)
        num = abs(num);

    save = num;
    remainder = num;

    // calculating the power
    for (; num >= 10;)
    {
        num = num / 10;
        power = power * 10;
    }

    cout << endl
         << "The individual digits are: ";

    //  Printing individual digits and calculating the sum. The task can be done both by using math library and by self calculating the power.
    for (; remainder > 0;)
    {
        // quotient = remainder / pow(10, i);
        quotient = remainder / power;
        // save = save % pow(10, i);
        cout << quotient << " ";
        sum += quotient;
        // remainder = remainder % static_cast<long long>(pow(10, i));
        remainder = remainder % power;
        power = power / 10;
    }

    cout << endl
         << "Sum of individual digits of " + to_string(save) + " is: " << sum << endl
         << endl;

    return 0;
}
