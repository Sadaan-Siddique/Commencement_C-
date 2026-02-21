#include <iostream>
using std::cout, std::cin, std::endl;

// this function will ask from user to either enter more marks or not
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
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; // to handle invalid commands entered
        addMarksFunc(size); // I have used recursion to again ask from user. It'll not affect my code
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
        if (i == (size - 1)) // when i is equal to n - 1, then this will take confirmity from user to either end the loop or not
            addMarksFunc(size);
    }

    cout<<"\nMarks are: \n"; // will print marks
    for (int i = 0; i < size; i++)
        cout << "Student " << (i + 1) << " : " << *(marksArrPtr + i) << endl;

    delete[] marksArrPtr;
    marksArrPtr = nullptr;

    return 0;
}