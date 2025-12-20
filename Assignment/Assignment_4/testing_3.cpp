#include <iostream>
using namespace std;

int main()
{
    // Input elevation map
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);

    int leftMax[n];
    int rightMax[n];

    // Step 1: Build leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = (height[i] > leftMax[i - 1])
                         ? height[i]
                         : leftMax[i - 1];
    }

    // Step 2: Build rightMax array
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = (height[i] > rightMax[i + 1])
                          ? height[i]
                          : rightMax[i + 1];
    }

    // Step 3: Calculate trapped water
    int totalWater = 0;
    for (int i = 0; i < n; i++)
    {
        int waterAtI = min(leftMax[i], rightMax[i]) - height[i];
        if (waterAtI > 0)
            totalWater += waterAtI;
    }

    cout << "height: ";
    for (int value : height)
        cout << value << " ";

    cout << endl
         << "LeftMax: ";
    for (int value : leftMax)
        cout << value << " ";

    cout << endl
         << "RightMax: ";
    for (int value : rightMax)
        cout << value << " ";

    cout << endl
         << "Total trapped water = " << totalWater << endl;

    return 0;
}
