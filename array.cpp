#include <iostream>
using namespace std;

int main()
{
    size_t s = sizeof(long long);

    int arr[5] = {12};
    // arr[0] = 56;
    // arr[1] = 60;

    // Writing out of bounds. BAD!
    arr[5] = 67;

    for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        cout << "arr[" << i << "] : " << arr[i] << endl;

    cout << arr[6] << endl // redaing out of bounds will give a garbage value
         << arr << endl;   // will return the index of first element of arr

    cout << endl
         << s << " bytes" << endl;

    int new_arr[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(new_arr) / sizeof(new_arr[0]); // Using size_t for array size. It will print the number of elements in array;  like: 20 / 4 = 5
    std::cout << "Array size: " << array_size << std::endl;
    cout << sizeof(new_arr) << endl
         << sizeof(char) << endl
         << endl;
    // ranged base for loop
    for (int elements : new_arr)
    {
        cout << "new_arr[" << elements << "] " << endl;
    }

    long double num = 560;
    cout << endl
         << endl
         << sizeof(num) << endl;
}