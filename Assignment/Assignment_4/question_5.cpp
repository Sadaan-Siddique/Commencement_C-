#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int nums[] = {1, 5, 9, 1, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    // int rowsSize = (numsSize - 1) * numsSize;
    int rowsSize = 0;
    int row = 0;
    int indexDiff = 1, valueDiff = 4;
    bool isPair = false;

    for (int i = 0; i < numsSize; i++)
        for (int j = 0; j < numsSize; j++)
            if ((i != j) && (abs(i - j) <= indexDiff) && (abs(nums[i] - nums[j]) <= valueDiff))
            {
                isPair = true;
                cout << "i : " << i << " | j : " << j << endl;
                cout << "nums[" << i << "] : " << nums[i] << " | nums[" << j << "] : " << nums[j] << endl
                     << endl;
                rowsSize++;
            }
    int pairs[rowsSize][2] = {0};
    for (int i = 0; i < numsSize; i++)
        for (int j = 0; j < numsSize; j++)
        {
            if ((i != j) && (abs(i - j) <= indexDiff) && (abs(nums[i] - nums[j]) <= valueDiff))
            {
                pairs[row][0] = nums[i];
                pairs[row][1] = nums[j];
                row++;
            }
        }

    cout << endl
         << endl;
    for (int i = 0; i < rowsSize; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << "pairs[i][j] : " << pairs[i][j] << endl;
        cout << endl;
    }

    (isPair ? cout << "True, Pair Exists." : cout << "False, Pair doesn't Exists.");
}