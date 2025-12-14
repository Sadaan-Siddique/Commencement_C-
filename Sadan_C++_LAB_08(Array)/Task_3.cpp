#include <iostream>
using namespace std;

int main()
{
    int marks[5];
    int student = 0;

    cout << "Enter marks of 5 students one by one: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }

    cout << endl
         << "Marks you entered: " << endl;

    for (int mark : marks)
        cout << "Student " << ++student << " : " << mark << endl;

    return 0;
}