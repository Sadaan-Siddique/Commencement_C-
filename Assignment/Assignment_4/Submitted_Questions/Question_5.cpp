#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int nums[] = {1, 5, 9, 1, 5, 9};
    // int nums[] = {1, 2, 3, 1};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int rowsSize = 0;
    int row = 0;
    int indexDiff = 0, valueDiff = 0;

    cout << "Enter index difference: ";
    cin >> indexDiff;
    cout<<"Enter value difference: ";
    cin >> valueDiff;

    bool isPair = false;

    for (int i = 0; i < numsSize; i++)
        for (int j = 0; j < numsSize; j++)
            if ((i != j) && (abs(i - j) <= indexDiff) && (abs(nums[i] - nums[j]) <= valueDiff))
            {
                isPair = true;
                rowsSize++;
            }


    (isPair ? cout << "True, Pair Exists." : cout << "False, Pair doesn't Exists.");

    return 0;
}