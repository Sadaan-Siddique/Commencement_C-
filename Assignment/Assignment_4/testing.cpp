#include <iostream>
using namespace std;

inline int occupySpace(int minIn, int maxIn, int height[5])
{
    int sum = 0;
    for (int i = (minIn + 1); i < maxIn; i++)
        sum += height[i];
    return sum;
}
int main()
{
    int height[8] = {1, 0, 5, 1, 0, 2, 0, 1};
    int absMax = 0, localMax = 0, absIn = 0, localIn = 0, difference = 0, space = 0, extraSpace = 0, actualWaterSpace = 0;

    // do
    // {
    //     cout << "Enter height for w = " << size - 1<<" : ";
    //     cin >> h;
    //     height[size - 1];
    //     size++;
    // }while(h > -1);

    for (int i = 0; i < (sizeof(height) / sizeof(height[0])); i++)
    {
        if (height[i] > absMax)
        {
            localIn = absIn;
            absIn = i;
            localMax = absMax;
            absMax = height[i];
        }
        else if (height[i] > localMax)
        {
            localMax = height[i];
            localIn = i;
        }
    }

    if (absIn > localIn)
    {
        difference = absIn - (localIn + 1);
        extraSpace = occupySpace(localIn, absIn, height);
    }

    else
    {
        difference = localIn - (absIn + 1);
        extraSpace = occupySpace(absIn, localIn, height);
    }
    space = localMax * difference;
    actualWaterSpace = space - extraSpace;

    cout << absMax << " " << localMax << endl;
    cout << absIn << " " << localIn << endl;
    cout << space << endl;
    cout << actualWaterSpace << endl;

    return 0;
}