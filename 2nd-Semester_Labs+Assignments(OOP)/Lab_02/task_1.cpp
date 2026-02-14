#include <iostream>
#include <bitset>
using std::cout; 
using std::endl;

constexpr int READ = 4;    // 100
constexpr int WRITE = 2;   // 010
constexpr int EXECUTE = 1; // 001

int main()
{
    int permission{0};

    permission |= READ;    // 100 = 4
    permission |= EXECUTE; // 101 = 5

    if ((permission & WRITE) != 0)
        cout << "WRITE permission is granted." << endl;
    else
        cout << "WRITE permission is not granted." << endl;

    permission |= WRITE;     // 111 = 7
    permission &=(~EXECUTE); // 110 = 6

    cout << "Based on the binary form of " << permission << " : " << std::bitset<3>(permission) << endl;

    if ((permission & (WRITE | READ)) == (WRITE | READ))
        cout << "READ and WRITE permissions are granted." << endl;

    if ((permission & (WRITE | EXECUTE)) == (WRITE | EXECUTE))
        cout << "WRITE and EXECUTE permissions are granted." << endl;

    if ((permission & (READ | EXECUTE)) == (READ | EXECUTE))
        cout << "READ and EXECUTE permissions are granted. " << endl;

    if ((permission & (READ | WRITE | EXECUTE)) == (READ | WRITE | EXECUTE))
        cout << "READ WRITE and EXECUTE, all permissions are granted. " << endl;

    return 0;
}