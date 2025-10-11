// TASK_02
// Write a program that takes input an intger and then output both the individual digits of the input number and the sum of the digits.
// For a negative number, use abs(number) => number will become positive.

#include <iostream>
#include <cmath> // for pow
#include <string>
using namespace std;

int main()
{
    long long num, power = 1, remainder, sum = 0;
    cout << "Enter a number: ";
    cin >> num;

    // Make positive
    if (num < 0)
    {
        num = llabs(num); // or abs, but llabs is safer for long long
    }

    // save = num;

    // Special case: if num is 0, we want to print digit “0”
    if (num == 0)
    {
        cout << endl
             << "The individual digits are: 0" << endl;
        cout << "Sum of individual digits of " << num << " is: 0" << endl;
        return 0;
    }

    // Compute highest power of 10 ≤ num
    while (num / power >= 10)
    {
        power *= 10;
    }

    cout << endl
         << "The individual digits are: ";

    remainder = num;

    while (power > 0)
    {
        long long digit = remainder / power;
        cout << digit << " ";
        sum += digit;

        remainder = remainder % power;
        power /= 10;
    }

    cout << endl
         << "Sum of individual digits of " << num << " is: " << sum
         << endl
         << endl;

    return 0;
}









int main_my_written()
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
