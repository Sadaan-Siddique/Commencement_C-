#include <iostream>
using namespace std;

// n = no. of terms
// a = first term
// d = common difference
int main()
{
    int num = 0, a = 2, d = 2, num_2 = 0;
    float n = 0;
    cout << endl
         << "Enter an integer between 0 and 101 : ";
    cin >> num;

    if (num <= 0 || num > 100)
    {
        main();
        return 0;
    }
    cout << endl;
    num_2 = num;

    if (num % 2 != 0)
    {
        cout << "Even numbers between 0 and " << num << " are : ";
        num -= 1;
    }
    else
    {
        cout << "Even numbers between 0 and " << num << " (inclusive) are : ";
    }

    n = num / 2;

    while (num != 0)
    {
        cout << num << " ";
        num -= 2;
    }

    cout << endl
         << endl
         << ((num_2 % 2 != 0)
                 ? ("Sum of even numbers between 0 and " + to_string(num_2) + " is : ")
                 : ("Sum of even numbers between 0 and " + to_string(num_2) + " (inclusive) is : "));

    cout << (n / 2) * (2 * a + (n - 1) * d) << endl
         << endl;

    return 0;
}