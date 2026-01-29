// My code of Question 3 will also work for question 4 (create random password characters)
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int passLength = 0;          // n
    int passDistinctSymbols = 0; // k
    int randNum = 0;
    char randChar = ' ';
    string password = "";

    // Taking length of the password and number of distinct symbols in the password
    do
    {
        cout << "Enter \"passwrod length\" (greater than 3): ";
        cin >> passLength;
        cout << "Enter \"passwrod distinct symbols\" (greater than 2): ";
        cin >> passDistinctSymbols;
    } while (passDistinctSymbols < 2 || passLength < 3);

    int Min = 97;
    int Max = 122;

    // seeding time 0
    srand(time(0));

    for (int i = 1; i <= min(passDistinctSymbols, passLength); i++)
    {
        bool isRandCharEqCh = false;
        randNum = rand() % (Max - Min + 1) + Min; // this expression will only generate numbers from 97 to 122
        randChar = (char)randNum;
        for (int ch : password)
            if (randChar == ch)
            {
                i--;
                isRandCharEqCh = true;
            }

        (isRandCharEqCh ? password : password += randChar);
    }

    if (passDistinctSymbols < passLength)
        for (int i = 1; i <= (passLength - passDistinctSymbols); i++)
        {
            randNum = rand() % (passLength - passDistinctSymbols); // this expression will only generate numbers from 0 to (passLength - passDistinctSymbols)
            int size = password.length() - 1;
            if (password[size] == password[randNum]) // at this point, password string has length = passDistinctSymbols but have indices range from 0 to (passDistinctSymbols - 1)
            {
                i--;
                continue;
            }
            password += password[randNum];
        }

    cout << endl
         << "Password generated is: " << password << endl;


    return 0;
}