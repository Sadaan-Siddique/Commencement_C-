#include <iostream>
using namespace std;

int main()
{
    // Declaring Variables
    int base = 0, exponent = 0;
    long long calc_power = 1;

    // Taking Inputs
    cout << "Enter Base (integer): ";
    cin >> base;

    cout << "Enter Exponent (integer): ";
    cin >> exponent;

    // Error Handling
    if (base == 0 && exponent == 0)
    {
        cout << "Undefined." << endl;
        return 0;
    }

    // Calculating powers for negative and positive exponents both.

    // If user enters negative power, it'll handle it
    if (exponent < 0)
    {
        for (int i = 1; i <= -exponent; i++)
        {
            calc_power *= base;
        }
        cout << "(" << base << ")"
             << "^"
             << "(" << exponent << ")"
             << " = "
             << 1 << "/" << calc_power << " = " << (1.0 / calc_power)
             << endl;
    }
    // For positive power
    else
    {
        for (int i = 1; i <= exponent; i++)
        {
            calc_power *= base;
        }
        cout << "(" << base << ")"
             << "^"
             << "(" << exponent << ")"
             << " = "
             << calc_power
             << endl;
    }

    // End
    cout << "______________"
         << endl
         << endl;

    return 0;
}