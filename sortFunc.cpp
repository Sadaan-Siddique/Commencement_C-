#include <iostream>
using namespace std;

void sortArrFunc(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = *(ptr + i);
        for (int j = 0; j < size; j++)
            if (min < *(ptr + j))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
    }
    return;
}
int main()
{
    int size = 8;
    bool isMin = false;
    int unsortedArr[size] = {2, 4, 3, 1, 0, 5, 70, 45};
    // sortArrFunc(unsortedArr, size);
    for (int i = 0; i < size; i++)
    {
        int min = unsortedArr[i];
        for (int j = 0; j < size; j++)
            if (min < unsortedArr[j])
            {
                int temp = unsortedArr[i];
                unsortedArr[i] = unsortedArr[j];
                unsortedArr[j] = temp;
            }
    }
    for (int val : unsortedArr)
        cout << val << " ";
}