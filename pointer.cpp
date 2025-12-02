#include <iostream>
using namespace std;

void reverseNum(int num)
{
    int lastDigit = 0, storeNumByMethod1 = num, power = 1, storeNumByMethod2 = 0;
    while (storeNumByMethod1 > 10)
    {
        storeNumByMethod1 /= 10;
        power *= 10;
    }
    storeNumByMethod1 = 0;
    while (num > 0)
    {
        lastDigit = num % 10;
        cout << lastDigit;
        storeNumByMethod1 += lastDigit * power;
        storeNumByMethod2 = storeNumByMethod2 * 10 + lastDigit;
        num /= 10;
        power /= 10;
    }
    cout << endl
         << "Storing reverse number in storeNumByMethod1 variable: " << storeNumByMethod1 << endl
         << "Storing reverse number in storeNumByMethod2 variable: " << storeNumByMethod2;
}
int main()
{
    int num = 0;
    cout << "Enter any positive integer: ";
    cin >> num;
    reverseNum(num);
    return 0;
}

void updateHigh(int *ptr1, int *ptr2)
{
    if (*ptr1 > *ptr2)
        *ptr1 += 1;
    else if (*ptr2 > *ptr1)
        *ptr2 += 1;
    else
        return;
}

int main_1()
{
    int num1 = 0, num2 = 0;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    updateHigh(&num1, &num2);

    cout << "Number 1: " << num1 << "\nNumber 2: " << num2 << endl;
    return 0;
}