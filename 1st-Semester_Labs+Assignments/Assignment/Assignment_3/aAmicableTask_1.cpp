#include <iostream>
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
bool isAmicable(int numOne = 0, int numTwo = 0)
{
    if (factors(numOne) == numTwo && factors(numTwo) == numOne)
        return true;
    else
        return false;
}

int main()
{
    int numOne = 0, numTwo = 0;

    // This do while loop checks whether the datatype entered is correct or not
    do
    {
        cout << "Enter first number of pair: ";
        cin >> numOne;

        // it'll take the second input if the first input is of correct datatype
        if (!cin.fail())
        {
            cout << "Enter second number of pair: ";
            cin >> numTwo;
        }

        if (cin.fail())
        {
            cout << "INVALID INPUT! Enter integer datatype. " << endl;
            // cin.clear() clears the stream of I/O which is stuck with failbit stream state flag
            cin.clear();
            // cin.ignore() clears the wrong data that is stuck in I/O stream and read the stream fully till \n
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            break;
    } while (true);

    // Calling isAmicable function
    if (isAmicable(numOne, numTwo))
        cout << endl
             << "Yes, the pair is amicable. " << endl;
    else
        cout << endl
             << "No, the pair isn't amicable." << endl;

    return 0;
}
