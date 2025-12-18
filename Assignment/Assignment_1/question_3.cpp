#include <iostream>
using namespace std;

// Creating a function to do calculation, it'll return a boolean.
bool isPrime(long long num_isPrime)
{
    // Error handling
    if (num_isPrime <= 1)
        return false;
    if (num_isPrime == 2)
        return true;
    if (num_isPrime % 2 == 0)
        return false;
    // Checking is a number prime or not...
    for (long long i = 3; i < num_isPrime; i += 2)
    {
        if ((num_isPrime % i) == 0)
        {
            return false;
        }
    }
    return true;
}

// main function
int main()
{
    // Declaring variable
    long long num_main = 0;

    // Taking input
    cout << "Enter any positive number: ";
    cin >> num_main;

    // Calling isPrime() function and passing it an argument.
    if (isPrime(num_main))
    {
        cout << num_main << " is a prime number." << endl;
        return 0;
    }
    else
    {
        cout << num_main << " is not a prime number." << endl;
        return 0;
    }
}