#include <iostream>
using std::cout, std::cin, std::endl;

int main()
{
    int size{};
    cout << "Enter the size of array: ";
    cin >> size;
    int *arrPtr = new int[size]; // creating an array on heap

    for (int i = 0; i < size; i++) // taking integer values from user
    {
        cout << "Enter integer " << (i + 1) << " : ";
        cin >> *(arrPtr + i);
    }

    for (int i = 0; i < (size / 2); i++) // this loop will run until size / 2 index reach
    {
        // below operations are used to reverse the elements of array
        *(arrPtr + i) += *(arrPtr + size - (i + 1));
        *(arrPtr + size - (i + 1)) = *(arrPtr + i) - *(arrPtr + size - (i + 1));
        *(arrPtr + i) -= *(arrPtr + size - (i + 1));
    }

    for (int i = 0; i < size; i++) // to display the elements
        cout << *(arrPtr + i) << " ";

    delete[] arrPtr;
    arrPtr = nullptr;
    return 0;
}