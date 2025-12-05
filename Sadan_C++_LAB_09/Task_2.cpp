// Task 2 — Print a Number Pattern Using Direct & Indirect Recursion 
#include <iostream>
using namespace std;

// Via Direct Recursion
void directRecursion(int num)
{
    if (num == 0)
        return;
    cout << num << " ";

    directRecursion(num - 1);

    cout << num << " ";
}

// Via Indirect Recursion
void indirectRecursionUp(int num)
{
    if (num == 0)
        return;
    cout << num << " ";
}

void indirectRecursionDown(int num)
{
    if (num == 0)
        return;
    cout << num << " ";
    indirectRecursionDown(num - 1);
    indirectRecursionUp(num);
}

int main()
{
    int n = 0;
    do
    {
        cout << "Enter any positive number: ";
        cin >> n;
    } while (n < 0);

    cout << "Output via direct recursion: ";
    directRecursion(n);
    cout << endl;

    cout << "Output via Indirect recursion: ";
    indirectRecursionDown(n);
    cout << endl;

    return 0;
}