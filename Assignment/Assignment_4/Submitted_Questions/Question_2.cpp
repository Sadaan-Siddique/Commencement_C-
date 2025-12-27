#include <iostream>
using namespace std;

int main()
{
    int height[] = {4, 2, 0, 3, 2, 5};
    // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1,7,0,0,8};

    int size = sizeof(height) / sizeof(height[0]);
    int waterblocks = 0, perBlock = 0;
    int maxH = height[0], maxIn = 0;

    // Right Maximum
    int rightMax[size];
    rightMax[size - 1] = height[size - 1];

    for (int i = (size - (1 + 1)); i >= 0; i--)
        rightMax[i] = ((height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1]);

    // Left Maximum
    int leftMax[size];
    leftMax[0] = height[0];

    for (int i = 1; i < (size); i++)
        leftMax[i] = ((height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1]);

    // Counting water Blocks
    for (int i = 0; i < size; i++)
    {
        if (rightMax[i] < leftMax[i])
            perBlock = rightMax[i] - height[i];
        else if (rightMax[i] >= leftMax[i])
            perBlock = leftMax[i] - height[i];
        if (perBlock > 0)
            waterblocks += perBlock;
    }

    // Printing the three arrays formed
    cout << "height: ";
    for (int value : height)
        cout << value << " ";

    cout << endl
         << "rightMax: ";
    for (int value : rightMax)
        cout << value << " ";

    cout << endl
         << "leftMax: ";
    for (int value : leftMax)
        cout << value << " ";

    cout << endl
         << "Total water trapped: " << waterblocks << endl
         << endl;

    // ASCII Histograms
    int barHeight = 0, waterHeight = 0;

    cout << "ASCII Histograms" << endl
         << endl;

    for (int i = (size - 1); i >= 0; i--)
    {
        cout << i << " |";
        for (int j = 0; j < size; j++)
        {
            waterHeight = min(rightMax[j], leftMax[j]);
            barHeight = height[j];
            if (i == 0)
                break;
            if (i <= barHeight)
                cout << "== ";
            else if (i > barHeight && i <= waterHeight)
                cout << "** ";
            else
                cout << "   ";
        }
        if (i == 0)
            for (int j = 0; j <= size; j++)
                cout << "---";

        cout << endl;
    }
    cout << "   ";
    for (int i = 0; i < size; i++)
        cout << i << "  ";

    return 0;
}