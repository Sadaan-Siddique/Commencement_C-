#include <iostream>
using namespace std;

bool isPrime(long long num_isPrime)
{
    if (num_isPrime <= 1)
        return false;
    if (num_isPrime == 2)
        return true;
    if (num_isPrime % 2 == 0)
        return false;
    for (long long i = 3; i < num_isPrime; i += 2)
    {
        if ((num_isPrime % i) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long num_main = 0;

    cout << "Enter any positive number: ";
    cin >> num_main;

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