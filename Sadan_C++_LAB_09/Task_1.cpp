// Task 1 — Sum of Digits Using Recursion
#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10 + sumOfDigits(n / 10));
}

int main()
{
    int num = 0;
    cout << "Enter any positive number: ";
    if (!(cin >> num))
    {
        cout << "Invalid input!" << endl;
        return 0;
    }
    
    long long n = (num < 0) ? -num : num;
    cout << "Sum of digits of " << num << " are: " << sumOfDigits(num);
    return 0;
}