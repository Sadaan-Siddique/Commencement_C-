#include <iostream>
using std::cout, std::cin, std::endl;

// this function will ask from user to either enter integers or not
void addIntFunc(int &n)
{
    char yN = ' ';
    int additionalInts{};
    cout << "Want to add more Integers? (Y/N): ";
    cin >> yN;
    switch (yN)
    {
    case 'Y':
        cout << "Enter number of extra integers: ";
        cin >> additionalInts;
        n += additionalInts;
        break;
    case 'N':
        return;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; // to handle invalid commands entered
        addIntFunc(n); // I have used recursion to again ask from user. It'll not affect my code
    }
    return;
}

int main()
{
    int n{3};
    int *intArrPtr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter integer " << (i + 1) << " : ";
        cin >> *(intArrPtr + i);

        static int maxValue = *intArrPtr; // this maxValue variable will initialize only at first iteration due to statis keyword

        if (i == (n - 1)) // when i is equal to n - 1, then this will take confirmity from user to either end the loop or not
            addIntFunc(n);
        if (maxValue < *(intArrPtr + i)) // will check the maximum value
            maxValue = *(intArrPtr + i);
        if (i == (n - 1))
            cout << "\nMaximum Integer Value entered : " << maxValue;
    }

    delete[] intArrPtr;
    intArrPtr = nullptr;

    return 0;
}