// In C++, stream state flags are a set of status indicators managed by input/output (I/O) stream objects (like std::cin, std::cout, and file streams) to report the outcome of operations and track the stream's condition. They are defined in the std::ios_base::iostate type and help programmers handle errors and specific conditions like reaching the end of a file.
// Checking Stream States
// You can check the state of a stream using specific member functions:
// good(): Returns true if none of the error flags (eofbit, failbit, or badbit) are set.
// eof(): Returns true if eofbit is set.
// fail(): Returns true if failbit or badbit is set. This is the most common function for general error checking.
// bad(): Returns true if badbit is set.
// operator!: The stream object can be used directly in boolean contexts (e.g., if (!stream)), which acts as a synonym for fail().
// You can also use the clear() function to reset the flags. Calling stream.clear() without arguments resets all flags back to goodbit, allowing you to attempt further I/O operations if the error was recoverable.

#include <iostream>
#include <limits>
#include <typeinfo>
using namespace std;

int counter(int num, int &index)
{
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
        {
            cout << i << " ";
            index++;
        }

    return index;
}

int main()
{
    int numOne = 0, numTwo = 0, index = 0, indexOne = 0, indexTwo = 0;

    cout << "Enter number 1 and 2: ";

    do
    {
        cout << "Enter first number of pair: ";
        cin >> numOne;
        if (!cin.fail())
        {
            cout << "Enter second number of pair: ";
            cin >> numTwo;
        }
        // what happens inside cin >> numOne when the value typed is larger than what an int can hold? C++ never stores this value in numOne

        if (cin.fail())
        {

            cout << "Invalid input! Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Think of streamsize as a special number type that C++ uses to represent:

            // 👉 “How many characters are in a stream?”
            // streamsize = a large integer type used for counting characters in streams.

            // A stream means input/output channels like:
            // cin (keyboard input)
            // cout (screen output)
            // file streams
            // string streams

            // So streamsize is used for:
            // sizes
            // lengths
            // counts of characters
            // buffer sizes
        }
        else
            break;

    } while (true);

    counter(numOne, indexOne);

    int factorsOne[indexOne];

    for (int i = 1; i <= numOne; i++)
        if (numOne % i == 0)
        {
            factorsOne[index] = i;
            index++;
        }
    index = 0;

    cout << endl;
    counter(numTwo, indexTwo);

    int factorsTwo[indexTwo];

    for (int i = 1; i <= numOne; i++)
        if (numTwo % i == 0)
        {
            factorsTwo[index] = i;
            index++;
        }

    // cout << endl
    //      << "Factors of " << numOne << " are: ";
    // for (int i = 0; i < indexOne; i++)
    //     cout << factorsOne[i] << " ";

    // cout << endl
    //      << "Factors of " << numTwo << " are: ";
    // for (int i = 0; i < indexTwo; i++)
    //     cout << factorsTwo[i] << " ";

    // cout << endl
    //      << typeid(numeric_limits<int>::max()).name();
}