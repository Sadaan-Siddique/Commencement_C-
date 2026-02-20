#include <iostream>
using std::cout, std::cin, std::endl;

void addMarksFunc(int &size)
{
    char yN = ' ';
    int additionalStds{};
    cout << "Want to add more marks? (Y/N): ";
    cin >> yN;
    switch (yN)
    {
    case 'Y':
        cout << "Enter number of additional students: ";
        cin >> additionalStds;
        size += additionalStds;
        break;
    case 'N':
        return;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n";
        addMarksFunc(size);
    }
    return;
}

int main()
{
    int size{3};
    int *marksArrPtr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter marks of student " << (i + 1) << " : ";
        cin >> *(marksArrPtr + i);
        if (i == (size - 1))
            addMarksFunc(size);
    }
    cout<<"\nMarks are: \n";
    for (int i = 0; i < size; i++)
        cout << "Student " << (i + 1) << " : " << *(marksArrPtr + i) << endl;

    delete[] marksArrPtr;
    marksArrPtr = nullptr;

    return 0;
}