#include <iostream>
#include <fstream>
#include <limits>
#include <string>
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

int main()
{
    ifstream readingData;

    int num_1 = 0, num_2 = 0;
    char ch = ' ';
    string num = " ";
    readingData.open("pairs.txt");

    if (!(readingData.is_open()))
    {
        cout << "File can't be opened!" << endl;
        return 0;
    }

    // ' readingData >> variable ' does not read everything blindly. It only reads input that matches the type of variable. If it doesn’t match, reading fails, and the stream goes into a fail state.

    // What does get(ch) return?readingData.get(ch)
    // readingData.get(ch) reads exactly one character from the file, stores it in ch, does not skip anything, and tells you whether the read succeeded.
    // returns:
    //     ✅ true - like value if a character was successfully read
    // ❌ false if reading failed(usually at EOF)
    //                   That’s why we often write :
    //     while (readingData.get(ch))
    //     {
    //         // use ch safely
    //     }
    //     This loop :
    //         stops automatically at end of file
    //         never reads garbage
    //         never needs eof()

    while (readingData.get(ch))
    {
        if (ch >= '0' && ch <= '9')
        {
            num_1 = (int)ch - (int)'0';
            cout << num_1;
        }
        if (ch == ' ' || ch == '\n')
            cout << ch;
    }
    readingData.clear();  // clear eof & fail bits
    readingData.seekg(0); // move cursor back to start
    cout << endl
         << "Another Way:" << endl;
    //  eof() tabhi true hota hai jab stream ek aur read attempt karta hai aur fail ho jata hai.
    //     Matlab:
    // Last character read hone ke turant baad: EOF still false ✅
    // Agla read fail hoga → EOF true ❌
    while (readingData >> num_1 >> num_2)
    {
        cout << num_1 << " " << num_2 << endl;
        // Calling isAmicable function
        if (isAmicable(num_1, num_2))
            cout << endl
                 << "Yes, the pair is amicable. " << endl;
        else
            cout << endl
                 << "No, the pair isn't amicable." << endl;
    }

    readingData.close();

    return 0;
}