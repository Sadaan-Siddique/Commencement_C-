
// My written code for question 2

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declaration of Varibales
    int starting_num = 0, ending_num = 0, select = 0;

    // Taking inputs
    cout << "Enter starting number: ";
    cin >> starting_num;

    cout << "Enter ending number: ";
    cin >> ending_num;

    // Starting Do_while loop
    do
    {
        // Redecalring variables to initial value
        int nums_sum = 0, even_nums_sum = 0, odd_nums_sum = 0;
        string even_nums = "", odd_nums = "", multiples_five = "";

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
        cin >> select;

        // Handling selection error
        while (select < 0 || select > 4)
        {
            cout << "INVALID SELECTION. Please select from (0-4): ";
            cin >> select;
        }

        // Checking whether initial number is greater than final number or not
        if (starting_num > ending_num)
        {
            // Starting for loop
            for (int i = ending_num; i <= starting_num; i++)
            {
                switch (select)
                {
                // Sum of numbers
                case 1:
                    nums_sum += i;
                    break;
                // Even numbers
                case 2:
                {
                    if (i % 2 == 0)
                    {
                        even_nums = even_nums + " " + to_string(i) + " ";
                        even_nums_sum += i;
                    }
                    break;
                }
                // Odd numbers
                case 3:
                {
                    if (i % 2 != 0)
                    {
                        odd_nums = odd_nums + " " + to_string(i) + " ";
                        odd_nums_sum += i;
                    }
                    break;
                }
                // Multiples of 5
                case 4:
                {
                    if (i % 5 == 0)
                    {
                        multiples_five = multiples_five + " " + to_string(i) + " ";
                    }
                    break;
                }
                // Exit program
                case 0:
                {
                    cout << "Program Ended ______" << endl;
                    return 0;
                    break;
                }
                default:
                {
                    i = starting_num;
                    break;
                }
                }
            }
            // Ending for loop
        }
        else
        {
            // Starting for loop
            for (int i = starting_num; i <= ending_num; i++)
            {
                switch (select)
                {
                // Sum of numbers
                case 1:
                    nums_sum += i;
                    break;
                // Even numbers
                case 2:
                {
                    if (i % 2 == 0)
                    {
                        even_nums = even_nums + " " + to_string(i) + " ";
                        even_nums_sum += i;
                    }
                    break;
                }
                // Odd numbers
                case 3:
                {
                    if (i % 2 != 0)
                    {
                        odd_nums = odd_nums + " " + to_string(i) + " ";
                        odd_nums_sum += i;
                    }
                    break;
                }
                // Multiples of 5
                case 4:
                {
                    if (i % 5 == 0)
                    {
                        multiples_five = multiples_five + " " + to_string(i) + " ";
                    }
                    break;
                }
                // Exit program
                case 0:
                {
                    cout << "Program Ended ______" << endl;
                    return 0;
                    break;
                }
                default:
                {
                    i = ending_num;
                    break;
                }
                }
            }
            // Ending for loop
        }

        // Printing the statements
        switch (select)
        {
            // For Sum of numbers
        case 1:
        {
            cout << endl
                 << "Sum of numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << nums_sum << endl;
            break;
        }
        // For Even numbers
        case 2:
        {
            cout << endl
                 << "Even numbers from " << starting_num << " to " << ending_num << "(inclusive) are: " << even_nums << endl;
            cout << endl
                 << "Sum of even numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << even_nums_sum << endl;
            break;
        }
        // For Odd numbers
        case 3:
        {
            cout << endl
                 << "Odd numbers from " << starting_num << " to " << ending_num << "(inclusive) are: " << odd_nums << endl;
            cout << endl
                 << "Sum of odd numbers from " << starting_num << " to " << ending_num << "(inclusive) is: " << odd_nums_sum << endl;
            break;
        }
        // For multiples of 5
        case 4:
        {
            cout << endl
                 << "Multiplicative terms of 5 from " << starting_num << " to " << ending_num << "(inclusive) are: " << multiples_five << endl;
            break;
        }
        // Program ending
        case 0:
        {
            cout << "Program Ended ______" << endl;
            return 0;
            break;
        }
        default:
        {
            cout << "INVALID SELECTION. Please select from (0-4). ";
            break;
        }
        }

        cout << endl
             << "---------------------" << endl
             << endl;
    } while (select != 0);
    // Ending Do_while loop

    return 0;
}