#include <iostream>
#include <string>
using namespace std;

int main()
{
    int selection = 0, marks = 0;
    cout << "Please select a choice 1 or 2 or 3 : ";
    cin >> selection;
    cout << endl;
    if (selection < 1 || selection > 3)
    {
        main();
        return 0;
    }
    if (selection == 3)
    {
        cout << "Program ended.";
        return 0;
    }

    do
    {

        cout << "Write your obtained marks (0-100) : ";
        cin >> marks;
        while (marks < 0 || marks > 100)
        {
            cout << "Write your obtained marks (0-100) : ";
            cin >> marks;
        }

        switch (selection)
        {
        case 1:
        {
            if (marks >= 50)
            {
                cout << "Passed!" << endl
                     << endl;
            }
            else
            {
                cout << "Failed!" << endl
                     << endl;
            }
            break;
        }
        case 2:
        {
            if (marks >= 80)
            {
                cout << "Distinction!" << endl
                     << endl;
            }
            else
            {
                cout << "No Distinction!" << endl
                     << endl;
            }
            break;
        }
        case 3:
        {

            return 0;
        }
        default:
        {
            main();
            return 0;
        }
        }
        cout << "Again select a choice 1 or 2 or 3 : ";
        cin >> selection;
    } while (selection == 1 || selection == 2);

    if (selection < 1 || selection > 3)
    {
        main();
        return 0;
    }

    cout << "Program ended.";
    return 0;
}