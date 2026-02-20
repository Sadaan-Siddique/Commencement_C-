#include <iostream>
using std::cout, std::cin, std::endl;

int main()
{
    int size {};
    cout<<"Enter the size of array: ";
    cin >> size;
    int *arrPtr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter integer " << (i + 1) << " : ";
        cin >> *(arrPtr + i);
    }

    for (int i = 0; i < (size / 2); i++)
    {
        *(arrPtr + i) += *(arrPtr + size - (i + 1));
        *(arrPtr + size - (i + 1)) = *(arrPtr + i) - *(arrPtr + size - (i + 1));
        *(arrPtr + i) -= *(arrPtr + size - (i + 1));
    }
    
    for (int i = 0; i < size; i++)
        cout << *(arrPtr + i) << " " ;

    return 0;
}