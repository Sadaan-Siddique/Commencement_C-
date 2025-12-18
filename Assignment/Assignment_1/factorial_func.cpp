#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaring Variables
    int num = 0;
    long long factorial = 1;
    string product = "";

    // Taking Input
    cout << "Enter any positive integer: ";
    cin >> num;
    cout << endl;

    // Error Handling
    while (num < 0)
    {
        cout << "Please enter a positive integer: ";
        cin >> num;
        cout << endl;
    }
    if (num == 0)
    {
        cout << "0! = 1 " << endl;
        return 0;
    }

    // Calculating and printing factorial
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
        // I have used switch case to not show this statement "1! = 1 = 1". It should print only 1! = 1.
        switch (i)
        {
        case 1:
        {
            product = to_string(i);
            cout << i << "! = " << factorial << endl;
            break;
        }
        default:
        {
            product = to_string(i) + " x " + product;
            cout << i << "! = " << product << " = " << factorial << endl;
            break;
        }
        }
    }
    cout << endl;

    return 0;
}