#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void tree(int n) {
    if (n <= 0) {
        return;
    }
    
    cout << n << " ";
    tree(n - 1);  // Left Branch
    tree(n - 2);  // Right Branch
}

int main() {
    tree(3);
    return 0;
}


void boomerang(int n) {
    if (n == 0) {
        return;
    }
    
    cout << n << " ";   // Action A
    boomerang(n - 1);   // Recursive Call
    cout << n << " ";   // Action B
}

int main_2() {
    boomerang(3);
    return 0;
}

int main_1()
{
    srand(time(0));

    int randomNum = rand() % 101;

    cout<<randomNum<<endl;
    return 0;
}