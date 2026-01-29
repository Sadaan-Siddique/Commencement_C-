// const arguments and default arguments
#include <iostream>
using namespace std;

long long calculateCube(const int base = 2)
{
    return (base * base * base);
}
int main()
{

    // Calling without passing any argument
    cout << calculateCube() << endl
         << "-------" << endl;

    // Calling with passing argument
    cout << calculateCube(5) << endl;

    return 0;
}