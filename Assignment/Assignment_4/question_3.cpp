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

    cout << "Enter \"passwrod length\" : ";
    cin >> passLength;
    cout << "Enter \"passwrod distinct symbols\" : ";
    cin >> passDistinctSymbols;
    while (passDistinctSymbols < 2)
    {
        cout << "\"Passwrod distinct symbols\" can't be lesser than 2!" << endl;
        cout << "Enter \"passwrod distinct symbols\" : ";
        cin >> passDistinctSymbols;
    }

    int Min = 97;
    int Max = 122;

    srand(time(0));

    for (int i = 1; i <= min(passDistinctSymbols, passLength); i++)
    {
        randNum = rand() % (Max - Min + 1) + Min; // this expression will only generate numbers from 97 to 122
        randChar = (char)randNum;
        cout << randChar;
        for (int ch : password)
            if (randChar == ch)
            {
                i--;
                continue;
            }
        password += randChar;
    }
    if (passDistinctSymbols < passLength)
        for (int i = 1; i <= (passLength - passDistinctSymbols); i++)
        {
            randNum = rand() % passDistinctSymbols; // this expression will only generate numbers from 0 to (passDistinctSymbols - 1)
            if (password[passDistinctSymbols + i - 2] == password[randNum]) // at this point, password string has length = passDistinctSymbols but have indices range from 0 to (passDistinctSymbols - 1)
            {
                i--;
                continue;
            }
            password += password[randNum];
        }

    cout << endl
         << password << endl;

    // time_t now;
    cout << rand() << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 100 << endl;
    cout << rand() % (Max - Min + 1) << endl;
    cout << rand() % (Max - Min + 1) + 1 << endl;
    cout << rand() % (Max - Min + 1) + Min << endl;
}