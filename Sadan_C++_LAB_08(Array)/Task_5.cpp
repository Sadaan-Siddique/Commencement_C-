#include <iostream>
using namespace std;

int main()
{
    int nums[50] = {0};
    int num = 0, index = 0, numSearch = 0, numIndex = 0;
    bool isFound = false;

    cout << "Enter n integers(Enter 0 to Exit the loop): ";

    do
    {
        cin >> num;
        nums[index] = num;
        index++;
    } while (num != 0);

    cout << "Now, enter number to search: ";
    cin >> numSearch;

    for (int i = 0; i < (index - 1); i++)
        if (nums[i] == numSearch)
        {
            numIndex = i;
            isFound = true;
        }

    (isFound ? cout << numSearch << " found at index " << numIndex << endl
             : cout << numSearch << " not found." << endl);

    return 0;
}