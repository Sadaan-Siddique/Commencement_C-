#include <iostream>
using namespace std;

int main()
{

    // for (int i = 1; i < 10; i++)
    // {
    //     for (int col=1; col <= i; col++)
    //     {
    //         for(int spacing = 1; spacing<=i;spacing++){
    //             cout << " ";
    //         }
    //         cout<<col;
    //     }
    //     cout<<endl;
    // }

    int i = 1, loops = 0;
    cout << "Enter the length of columns of diamond you want :";
    cin >> loops;

    for (; i < loops; i++)
    {
        for (int spacing = loops; spacing >= i; spacing--)
        {
            cout << " ";
        }
        for (int col = 1; col <= i; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    for (; i > 0; i--)
    {
        for (int spacing = loops; spacing >= i; spacing--)
        {
            cout << " ";
        }
        for (int col = 1; col <= i; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}