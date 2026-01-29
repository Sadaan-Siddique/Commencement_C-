#include <iostream>
using namespace std;

int main()
{
    int nums[50] = {0};
    int num = 0, index = 0, totalSum = 0;

    cout << "Enter n integers(Enter 0 to Exit the program): ";

    do
    {
        cin >> num;
        nums[index] = num;
        index++;
    } while (num != 0);

    for (int i = 0; i < (index - 1); i++)
        totalSum += nums[i];

    cout << "Sum = " << totalSum << endl;
    cout << "Average = " << totalSum / (index - 1) << endl;

    return 0;
}