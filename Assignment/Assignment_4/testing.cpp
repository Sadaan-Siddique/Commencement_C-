#include <iostream>
using namespace std;

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;
    int comparisons = 0, shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        if (j >= 0)
            comparisons++;
        arr[j + 1] = key;
    }
    cout<<comparisons<<endl;
}

int f(int &n)
{
    if (n == 0)
        return 0;
    n = n - 1;
    return n + f(n);
}

int main_4()
{
    int x = 3;
    cout << f(x) << endl;
    cout << endl
         << "Break::" << endl;
    cout << x << endl
         << endl;
    int a[2][2] = {{1, 2}, {3, 4}};
    int *p = &a[0][0];
    cout << *(p + 3);
}

int main_3()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    cout << p << endl;
    cout << *p << endl;
    cout << *(p++) << endl; // *p++ = *(p++)
    cout << (*p)++ << endl;
    cout << *p++ << " " << *(++p) << endl;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    return 0;
}

int main_2()
{
    int a = 10;
    int b = 7;
    int *ptr;
    // ptr = &a;
    // cout<<*ptr<<endl;
    ptr = &b;
    cout << *ptr << endl;
    cout << *++ptr << endl;

    int marks[5]{1, 2, 3, 4, 5};
    cout << marks << endl;
    cout << marks[0] << endl;
    cout << &marks[0] << endl;
    cout << *&marks[0] << endl;
    cout << *(&marks[0]) << endl;
    cout << marks[1] << endl;
    cout << marks[6] << endl;

    char chars[]{'S', 'a', 'd', 'a', 'a', 'n', '\0'};
    cout << chars << endl;
    cout << chars[5] << endl;
    cout << chars[6] << endl;
    cout << "sizeof: " << sizeof(chars) << endl;

    return 0;
}

inline int occupySpace(int minIn, int maxIn, int height[5])
{
    int sum = 0;
    for (int i = (minIn + 1); i < maxIn; i++)
        sum += height[i];
    return sum;
}
// int main()
// {
//     int height[8] = {1, 0, 5, 1, 0, 2, 0, 1};
//     int absMax = 0, localMax = 0, absIn = 0, localIn = 0, difference = 0, space = 0, extraSpace = 0, actualWaterSpace = 0;

//     // do
//     // {
//     //     cout << "Enter height for w = " << size - 1<<" : ";
//     //     cin >> h;
//     //     height[size - 1];
//     //     size++;
//     // }while(h > -1);

//     for (int i = 0; i < (sizeof(height) / sizeof(height[0])); i++)
//     {
//         if (height[i] > absMax)
//         {
//             localIn = absIn;
//             absIn = i;
//             localMax = absMax;
//             absMax = height[i];
//         }
//         else if (height[i] > localMax)
//         {
//             localMax = height[i];
//             localIn = i;
//         }
//     }

//     if (absIn > localIn)
//     {
//         difference = absIn - (localIn + 1);
//         extraSpace = occupySpace(localIn, absIn, height);
//     }

//     else
//     {
//         difference = localIn - (absIn + 1);
//         extraSpace = occupySpace(absIn, localIn, height);
//     }
//     space = localMax * difference;
//     actualWaterSpace = space - extraSpace;

//     cout << absMax << " " << localMax << endl;
//     cout << absIn << " " << localIn << endl;
//     cout << space << endl;
//     cout << actualWaterSpace << endl;

//     return 0;
// }