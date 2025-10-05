#include <iostream>
#include <string>
using namespace std;

int main()
{
    int selection = 0, marks = 0;

    do
    {
        cout << "Menu\n"
             << "1. Check if student passed\n"
             << "2. Check if student got distinction (marks ≥ 80)" << endl
             << "3. Exit\n"
             << "Enter choice : ";
        cin >> selection;

        switch (selection)
        {
        case 1:
        {
            cout << "Enter your obtained marks (0-100) : ";
            cin >> marks;
            while (marks < 0 || marks > 100)
            {
                cout << "Write your obtained marks (0-100) : ";
                cin >> marks;
            }
            if (marks >= 50)
            {
                cout << "Passed\n";
            }
            else
            {
                cout << "Failed\n";
            }
            break;
        }
        case 2:
        {
            cout << "Enter your obtained marks : ";
            cin >> marks;
            while (marks < 0 || marks > 100)
            {
                cout << "Write your obtained marks (0-100) : ";
                cin >> marks;
            }
            if (marks >= 80)
            {
                cout << "Distinction\n";
            }
            else
            {
                cout << "No Distinction\n";
            }
            break;
        }
        case 3:
        {
            cout << "Exiting program...\n";
            break;
        }
        default:
        {
            cout << "Please select a choice 1 or 2 or 3. " << endl;
        }
        }
        cout << endl;
    } while (selection != 3);

    return 0;
}
