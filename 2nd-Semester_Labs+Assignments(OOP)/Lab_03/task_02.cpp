#include <iostream>
using std::cout, std::cin, std::endl;

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
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n";
        addIntFunc(n);
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

        static int maxValue = *intArrPtr;

        if (i == (n - 1))
            addIntFunc(n);
        if (maxValue < *(intArrPtr + i))
            maxValue = *(intArrPtr + i);
        if (i == (n - 1))
            cout << "\nMaximum Integer Value entered : " << maxValue;
    }

    delete[] intArrPtr;
    intArrPtr = nullptr;

    return 0;
}