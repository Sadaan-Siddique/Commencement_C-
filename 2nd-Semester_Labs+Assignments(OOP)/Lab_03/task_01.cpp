// Memory is just a long sequence of numbered locations.
// Smaller numbers → Low addresses
// Bigger numbers → High addresses
// Think of it like house numbers on a street.

// (Low Addresses)

// 1️⃣ Text Segment (Code Segment)
// Contains compiled machine code
// Read-only
// Stores your functions
// Example:
// int main() { }
// The compiled instructions go here.

// 2️⃣ Data Segment
// Stores global and static variables.
// Example:
// int globalVar = 10;
// static int x = 5;
// There are two parts:
// Initialized data
// Uninitialized data (BSS segment)

// Heap
// Used for dynamic memory allocation
// Grows upward (towards higher addresses)
// Managed manually (new, delete)
// Example:
// int* arr = new int[5];

// Stack
// Used for local variables
// Stores function calls
// Grows downward (towards lower addresses)
// Example:
// void func() {
//     int x = 10;
// }
// Every function call creates a stack frame.

// (High Addresses)

// 5️⃣ Kernel Space
// This part is reserved for the Operating System.
// Your program CANNOT access it.
// Used by OS for:
// Device drivers
// Process control
// Memory management
// If your program tries to access it → Segmentation Fault 💥

// Why Stack and Heap Are Separate?
// Because:
// Stack is fast and automatic.
// Heap is flexible but slower.
// Separation prevents collision.
// If they collide → Stack Overflow or Memory Error.

// Your 16 GB RAM is NOT permanently divided into fixed parts like
// “2 GB for stack, 3 GB for heap, 1 GB for kernel”, etc.
// It does not work like slicing a cake.

// Physical RAM vs Process Memory
// You have:
// 16 GB Physical RAM
// But when your program runs, it does NOT directly see that 16 GB.
// It sees something called:
// Virtual Memory
// The Operating System (OS) creates a virtual address space for every process.

// Final Clear Answer
// If you have 16GB RAM:
// It is NOT pre-divided into fixed segments.
// Kernel uses memory as needed.
// Each process gets its own virtual address space.
// Heap and stack sizes grow dynamically.
// OS manages everything using paging.

#include <iostream>
using std::cout, std:: cin, std::endl;

int main(){
    int size {3};

    int *arrPtr = new int[size]; // by doing this, memory will allocate at run time
    // Memory for 3 integers is allocated in the heap.
    // arrPtr stores only the address of the first element.
    // The pointer does NOT store:
    // How many elements were allocated ❌
    // The total size ❌
    int arr[3];
    cout<<sizeof(*arrPtr)<<endl; // will give Size of one int
    cout<<sizeof(arr)<<endl; // will give Size of entire static array
    cout<<sizeof(arrPtr)<<endl; // will give Size of pointer On a 64-bit system:
                                // sizeof(pointer) = 8 bytes
    // sizeof does NOT work to find size of dynamic arrays. sizeof works at compile time, not runtime.


}