#include <iostream>
using namespace std;

int main()
{
    int units;
    bool delayed;
    double bill = 0;

    cout << "Enter your bill units : ";
    cin >> units;

    if (units <= 0)
    {
        cout << "Invalid Input. Units must be positive integer." << endl;
        return 0;
    }

    cout << "Is your payment delayed? (Yes=1 / No=0): ";
    cin >> delayed;

    // Nested if–else for tiered calculation
    if (units <= 100){
        bill = units * 10;
    }
    else if (units <= 300){
        bill = 100 * 10 + (units - 100) * 15;
    }
    else{
        bill = 100 * 10 + 200 * 15 + (units - 300) * 20;
    }

    // Add surcharge if >400
    if (units > 400){
        bill = bill*1.10;
        // bill = 0.10*bill + bill 
    }

    // Switch for late payment confirmation
    switch (delayed)
    {
    case true:
        bill += 500;
        cout << "Your Final Bill (with late fee) is : " << bill << endl;
        break;
    case false:
        cout << "Your Final Bill is : " << bill << endl;
        break;
    default:
        cout << "Invalid input for late payment. Enter 1 or 0." << endl;
    }

    return 0;
}
