#include <iostream>
using namespace std;

// Declaring the Value of Constant (Pi)
const double pi = 3.14159265358979323846;

int main()
{
    double radius, area, circum; // Declaring the variables required
    cout << "Enter Radius : ";
    cin >> radius;

    // Now, calculating the Area
    area = pi * radius * radius;

    // Calculating the Circumference
    circum = 2 * pi * radius;

    // Displaying Area and Circumference
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circum << endl;

    return 0;
}
