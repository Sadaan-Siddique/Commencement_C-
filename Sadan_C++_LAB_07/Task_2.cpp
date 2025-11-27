#include <iostream>

void goalScored(int &teamA, int &teamB, char scorer);
int main()
{
    int scoreA = 0, scoreB = 0;
    char whichTeam = ' ';

    do
    {
        std::cout << "Goal scored by which team (A/B)? ";
        std::cin >> whichTeam;

        while (whichTeam != 'A' && whichTeam != 'B')
        {
            std::cout << "Please select team (A/B)? ";
            std::cin >> whichTeam;
        }

        goalScored(scoreA, scoreB, whichTeam);

        std::cout << "Updated Score: Team A = " << scoreA << ", Team B = " << scoreB << std::endl;

        for (int i = 0; i <= 200000000; i++);

    } while (true);

    return 0;
}

void goalScored(int &teamA, int &teamB, char scorer)
{
    switch (scorer)
    {
    case 'A':
        teamA += 1;
        break;
    case 'B':
        teamB += 1;
        break;
    }
}