#include <iostream>
using namespace std;

int main_1()
{
    int x = 10;
    int *p = &x;
    int **dp = &p;

    cout<<x<<endl;
    cout<<p<<" "<<*p<<endl;
    cout<<dp<<" "<<*dp<<" "<<**dp<<endl;
    cout<<nullptr<<endl;
    return 0;
}


// Function takes a pointer to a pointer (int**)
void allocateAndAssign(int** ptr) {
    // 1. Allocate memory dynamically on the heap
    // 2. Assign the address of that memory to the pointer being pointed to
    *ptr = new int;

    // 3. Assign the value 25 to the newly allocated memory
    **ptr = 25;
}

int main() {
    // Initialize a pointer to null
    int* myPtr = nullptr;

    // Pass the address of the pointer to the function
    allocateAndAssign(&myPtr);

    // Verify the results
    if (myPtr != nullptr) {
        std::cout << "Value: " << *myPtr << std::endl;      // Outputs 25
        std::cout << "Address: " << myPtr << std::endl;
    }

    // Clean up memory
    delete myPtr;
    myPtr = nullptr;

    return 0;
}
