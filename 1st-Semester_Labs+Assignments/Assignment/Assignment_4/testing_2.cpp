#include <iostream>
using namespace std;

int rightMax(int In, int height[6])
{
    // (i + 1) < 6 &&
    if (In == 5)
        return height[5];
    for (int i = (In + 1); i < 6; i++)
        if ((height[i] > height[i + 1]))
            return i;
    return -1;
}
int main()
{
    int height[6] = {1, 0, 0, 2, 0, 3};
    int rightMaxIn = 0;

    for (int i = 0; i < (sizeof(height) / sizeof(height[0])); i++)
    {
        rightMaxIn = rightMax(i, height);
        cout << "For index " << i << ", right max height is: " << ((rightMaxIn >= 0) ? height[rightMaxIn] : rightMaxIn) << endl;
    }
    // if (height[i] < height[i - 1] && height[i] < height[i + 1])
    return 0;
}