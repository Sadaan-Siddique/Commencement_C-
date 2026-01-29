#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1,7,0,0,8};
    int height[] = {4, 2, 0, 3, 2, 5};
    // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    int size = sizeof(height) / sizeof(height[0]);
    int waterblocks = 0, perBlock = 0;

    // rightMax[] array stores the right maximum value for every element in height array
    int rightMax[size];
    rightMax[size - 1] = height[size - 1];

    for (int i = (size - (1 + 1)); i >= 0; i--)
        rightMax[i] = ((height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1]);

    // leftMax[] array stores the left maximum value for every element in height array
    int leftMax[size];
    leftMax[0] = height[0];

    for (int i = 1; i < (size); i++)
        leftMax[i] = ((height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1]);

    // this for loop will count every water block at the ith index and will add it to waterblocks
    for (int i = 0; i < size; i++)
    {
        if (rightMax[i] < leftMax[i])
            perBlock = rightMax[i] - height[i];
        else if (rightMax[i] >= leftMax[i])
            perBlock = leftMax[i] - height[i];
        if (perBlock > 0)
            waterblocks += perBlock;
    }

    cout << endl
         << "Total water trapped: " << waterblocks<<endl;

    return 0;
}