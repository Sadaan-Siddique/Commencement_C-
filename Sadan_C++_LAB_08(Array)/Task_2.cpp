#include <iostream>
using namespace std;

int main()
{
    int nums[50] = {0};
    int num = 0, index = 0;

    cout << "Enter any n positive integers(Enter 0 to Exit the program): ";
    do
    {
        cin >> num;
        nums[index] = num;
        index++;
    } while (num != 0);

    int minNum = nums[0], maxNum = nums[0];

    for (int i = 0; i < (index - 1); i++)
    {
        if (nums[i] > maxNum)
            maxNum = nums[i];

        if (nums[i] < minNum)
            minNum = nums[i];
            
    }
    cout << "Max Number = " << maxNum << endl;
    cout << "Min Number = " << minNum << endl;

    return 0;
}