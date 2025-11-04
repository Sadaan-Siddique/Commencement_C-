#include <iostream>
using namespace std;

// Declaring the Value of Constant (Pi)
const double pi = 3.14159265358979323846;

int main()
{
    int num_1 = 0, num_2 = 0, hcf = 0;

    cout << "Enter first number (positive): ";
    cin >> num_1;

    cout << "Enter second number (positive): ";
    cin >> num_2;
    if (num_1 > num_2)
    {
        for (int i = 1; i <= num_2; i++)
            if ((num_1 % i) == 0 && (num_2 % i) == 0)
                hcf = i;
    }
    else if (num_1 < num_2)
    {
        for (int i = 1; i <= num_1; i++)
            if ((num_1 % i) == 0 && (num_2 % i) == 0)
                hcf = i;
    }
    cout << endl
         << hcf << endl;

    return 0;
}
