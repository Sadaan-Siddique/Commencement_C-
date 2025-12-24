#include <iostream>
#include <fstream>
using namespace std;

bool isPrimeFunc(int number)
{
    if (number <= 1)
        return false;
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    int num = 0;
    bool isPrime = true;

    cout << "Enter any positive number: ";
    cin >> num;

    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }

    isPrime ? (cout << num << " is prime.") : (cout << num << " is not a prime.");
    cout << endl
         << endl;

    fstream writePrimes;

    writePrimes.open("Primes.txt", ios::out);

    if (!(writePrimes.is_open()))
    {
        cout << "File can't be opened." << endl;
        return 0;
    }

    int number = 2, prime = 0;

    writePrimes << "This file contains 10000 primes." << endl;

    while (prime <= 1000)
    {
        if (isPrimeFunc(number))
        {
            prime++;
            cout << number << endl;
            writePrimes << prime << ". " << number << endl;
        }
        number++;
    }

    writePrimes.close();

    return 0;
}