#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// This function will check whether the characters in string entered are only digits or not. It works on the logic that character is stored via its ASCII CODE.
bool isDigit(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch == ' '))
        return true;
    else
        return false;
}

int main()
{
    
    // Clear output.txt before appending new results
    ofstream clearFile("output.txt");
    clearFile.close();
    
    ofstream writingData;

    string pairs = " ";
    char digit = ' ';
    int pair_1 = 0, pair_2 = 0;
    bool isPeriod = false;

    writingData.open("pairs.txt");

    if (!(writingData.is_open()))
    {
        cout << "File can't be open!" << endl;
        return 0;
    }
    cout << "Writing in pairs.txt file (press '.' to exit the program): " << endl;

    while (!isPeriod)
    {
        // getline stops at \n and doesn't store it in variable
        getline(cin, pairs);
        // for (int i = 0; i < pairs.length(); i++)
        // Range based for loop. This loop will iterate each time for every character in string and as it finds a period'.' , it makes the isPeriod true and loop will break;
        for (char ch : pairs)
        {
            if (isDigit(ch))
                writingData << ch;
            if (ch == '.')
            {
                isPeriod = true;
                break;
            }
        }
        writingData << '\n';
        pairs = " ";
    }

    // Another way to write data with different logic:
    cout << endl
         << "Another way to write data with different logic: " << endl;
    writingData << "\nWriting by another method:\n";
    do
    {
        digit = ' ';
        digit = getchar();

        if ((digit >= '0' && digit <= '9') || (digit == ' ') || (digit == '\n'))
            writingData << digit;

    } while (digit != '.');

    // Another way to write data with different logic:
    cout << endl
         << "Another way to write data with different logic: " << endl;
    writingData << "\nWriting by another method:\n";
    cout << "Enter '0' to exit the program." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true)
    {
        cout << "Enter pair 1: ";
        cin >> pair_1;
        if (!(cin.fail()))
        {
            cout << "Enter pair 2: ";
            cin >> pair_2;
        }
        if (cin.fail())
        {
            cout << "INVALID DATATYPE! Enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pair_1 == 0 || pair_2 == 0)
            break;
        writingData << pair_1 << " " << pair_2 << "\n";
    }

    writingData.close();
    return 0;
}