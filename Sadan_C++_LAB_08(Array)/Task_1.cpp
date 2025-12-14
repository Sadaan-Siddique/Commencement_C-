#include <iostream>
using namespace std;

int main()
{
    int nums[50] = {0};
    int num = 0, evenCount = 0, oddCount = 0, index = 0;

    cout << "Enter n positive integers(Enter 0 to Exit the program): ";
    do
    {
        cin >> num;
        nums[index] = num;
        index++;
    } while (num != 0);

    for (int i = 0; i < (index - 1); i++)
    {
        if (nums[i] % 2 == 0)
            evenCount++;
        if (nums[i] % 2 != 0)
            oddCount++;
    }
    cout << "Even numbers = " << evenCount << endl;
    cout << "Odd numbers = " << oddCount << endl;

    return 0;
}