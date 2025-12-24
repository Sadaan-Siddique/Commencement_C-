#include <iostream>
#include <limits>
using namespace std;

// int minFunc(int num_1 = 0, int num_2 = 0, int num_3 = 0)
// {
//     if (num_1 < num_2 && num_1 < num_3)
//         return num_1;
//     else if (num_2 < num_1 && num_2 < num_3)
//         return num_2;
//     else if (num_3 < num_2 && num_3 < num_1)
//         return num_3;
//     else
//         return 1;
// }

int main()
{
    int num_1 = 0, num_2 = 0, num_3 = 0;
    int lcm = 0, i = 1;
    bool isLcm = false;

    do
    {
        cout << "Enter three numbers: ";
        cin >> num_1 >> num_2 >> num_3;
        if (cin.fail())
        {
            cout << "INVALID INPUT!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (num_1 == 0 || num_2 == 0 || num_3 == 0)
        {
            cout << "LCM is undefined when any number is zero." << endl;
            return 0;
        }
        else {
            num_1 = abs(num_1);
            num_2 = abs(num_2);
            num_3 = abs(num_3);
            break;
        }
    } while (true);

    cout << num_1 << " " << num_2 << " " << num_3 << endl;

    while (!isLcm)
    {
        if ((i % num_1 == 0) && (i % num_2 == 0) && (i % num_3 == 0))
        {
            isLcm = true;
            cout << i << endl;
            lcm = i;
        }
        i++;
    }

    (isLcm ? (cout << "LCM is: " << lcm << endl) : cout << "NO LCM found." << endl);

    // Lcm using recursion

    
}