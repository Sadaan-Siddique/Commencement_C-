#include <iostream>
using namespace std;

void calcSteps(int stepD, int &stepW, int i, int &highStep, int &hDay)
{
    stepW += stepD;
    if (stepD > highStep)
    {
        highStep = stepD;
        hDay = i;
    }
}
int main()
{
    // stepD = steps per day, stepW = steps per week, hDay = day of highest steps
    int stepD = 0, stepW = 0, hDay = 1, highStep = 0;

    for (int i = 1; i <= 7; i++)
    {
        cout << "Write steps of day " << i << " : ";
        cin >> stepD;
        calcSteps(stepD, stepW, i, highStep, hDay);
    }
    cout << endl
         << "Total steps per week are: " << stepW << "\nHighest steps are ' " << highStep << " ' for day ' " << hDay << " ' " << endl;
}