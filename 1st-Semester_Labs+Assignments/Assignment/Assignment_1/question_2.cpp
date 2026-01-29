#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaration of Varibales
    int starting_num = 0, start = 0, ending_num = 0, end = 0, selection = 0;

    // Taking inputs
    cout << "Enter starting number: ";
    cin >> starting_num;
    start = starting_num;

    cout << "Enter ending number: ";
    cin >> ending_num;
    end = ending_num;

    // Starting Do_while loop
    do
    {
        // If ending number is greater than starting number
        if (ending_num < starting_num)
        {
            start = ending_num;
            end = starting_num;
        }

        // Driven Menu
        cout << endl
             << "What do you want? " << endl;
        cout << "1. Sum of all the numbers from " << starting_num << " to " << ending_num << endl;
        cout << "2. Display all even numbers and their sum from " << starting_num << " to " << ending_num << endl;
        cout << "3. Display all odd numbers and their sum from " << starting_num << " to " << ending_num << endl;
        cout << "4. Display all multiples of 5 from " << starting_num << " to " << ending_num << endl;
        cout << "0. Exit the program " << endl;

        // selection of the menu
        cout << endl
             << "Now, select from (0-4): ";
        cin >> selection;

        // Handling selection error
        while (selection < 0 || selection > 4)
        {
            cout << "INVALID SELECTION. Please select from (0-4): ";
            cin >> selection;
        }
        cout << endl;

        // Variable to hold sum and written statements
        int nums_sum = 0;
        string output = "";

        // Starting Switch Case
        switch (selection)
        {
        // Sum of numbers
        case 1:
        {
            for (int i = start; i <= end; i++)
                nums_sum += i;
            cout << "Sum of numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << nums_sum << endl;
            break;
        }
        // Even numbers
        case 2:
        {
            for (int i = start; i <= end; i++)
                if (i % 2 == 0)
                {
                    nums_sum += i;
                    output += to_string(i) + " ";
                }
            if (output == "")
                output = "None";
            cout << "Even numbers from " << starting_num << " to " << ending_num << "(inclusive) are: " << output << endl;
            cout << endl
                 << "Sum of even numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << nums_sum << endl;
            break;
        }
        // Odd numbers
        case 3:
        {
            for (int i = start; i <= end; i++)
                if (i % 2 != 0)
                {
                    nums_sum += i;
                    output += to_string(i) + " ";
                }
            if (output == "")
                output = "None";
            cout << "Odd numbers from " << starting_num << " to " << ending_num << "(inclusive) are: " << output << endl;
            cout << endl
                 << "Sum of odd numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << nums_sum << endl;
            break;
        }
        // Multiples of 5
        case 4:
        {
            for (int i = start; i <= end; i++)
                if (i % 5 == 0)
                {
                    output += to_string(i) + " ";
                }
            if (output == "")
                output = "None";

            cout << endl
                 << "Multiplicative terms of 5 from " << starting_num << " to " << ending_num << "(inclusive) are: " << output << endl;
            break;
        }
        // Exiting Program
        case 0:
        {
            cout << "Program Ended ______" << endl;
            return 0;
            break;
        }
        // Invalid Selection
        default:
        {
            cout << "INVALID SELECTION. Please select from (0-4). ";
            break;
        }
        }
        // Ending Switch Case

        cout << endl
             << "---------------------"
             << endl;

        //  Loop for delaying the code for an instant of time
        for (int i = 0; i <= 400000000; i++)
            ;

    } while (selection != 0);
    // Ending Do_while loop

    return 0;
}
