#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// factors() function will find the sum of factors of a number
inline int factors(int num = 0)
{
    int factors = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            factors += i;
    return factors;
}

// isAmicable checks whether two numbers are amicable or not by calling the inline factors() function
bool isAmicable(int num_1 = 0, int num_2 = 0)
{
    if (factors(num_1) == num_2 && factors(num_2) == num_1)
        return true;
    else
        return false;
}

// Function for writing data in output.txt file
void writeData(bool isAmicable, int num_1, int num_2)
{
    ofstream writingData;

    writingData.open("output.txt", ios::app);
    if (!(writingData.is_open()))
    {
        cout << "File can't be opened!" << endl;
        return;
    }

    writingData << "Is the pair " << num_1 << " " << num_2 << " amicable? " << (isAmicable ? "Yes" : "No") << '\n';

    writingData.close();
    return;
}

// This function manually writes the data in pairs.txt file
void writeData()
{
    ofstream writingPairs;

    int num_1 = 0, num_2 = 0;

    writingPairs.open("pairs.txt");

    if (!(writingPairs.is_open()))
    {
        cout << "File can't be opened!" << endl;
        return;
    }

    cout << "Enter pairs in pairs.txt (enter '0' in any number to exit the program): " << endl;

    while (true)
    {
        cout << "Enter number 1: ";
        cin >> num_1;
        if (!(cin.fail()))
        {
            cout << "Enter number 2: ";
            cin >> num_2;
        }
        if (cin.fail())
        {
            cout << "INVALID DATATYPE! Enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (num_1 == 0 || num_2 == 0)
            break;
        writingPairs << num_1 << " " << num_2 << "\n";
    }

    writingPairs.close();
    return;
}
int main()
{
    // this function is for writing the pairs in pairs.txt file manually
    writeData();

    // reading the data of pairs from the pairs.txt file
    ifstream readingData;

    int num_1 = 0, num_2 = 0;

    readingData.open("pairs.txt");

    if (!(readingData.is_open()))
    {
        cout << "File can't be opened!" << endl;
        return 0;
    }
    // The loop will run till no input is received from pairs.txt
    while (readingData >> num_1 >> num_2)
    {
        cout << num_1 << " " << num_2;
        // Calling isAmicable()
        if (isAmicable(num_1, num_2))
        {
            cout << ": Yes, the pair is amicable. " << endl;
            // Calling writeData()
            writeData(true, num_1, num_2);
        }
        else
        {
            cout << ": No, the pair isn't amicable." << endl;
            // Calling writeData()
            writeData(false, num_1, num_2);
        }
    }

    readingData.close();

    return 0;
}