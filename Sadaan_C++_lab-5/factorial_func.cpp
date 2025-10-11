#include <iostream>

// Function to compute the factorial of a number iteratively
long long factorial(int n) {
    // Hint 1: Initialize a result variable to 1
    // We use `long long` because factorials grow very quickly
    long long result = 1;

    // Handle invalid input (negative numbers) and the special case of 0!
    if (n < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
        return -1; // Or some other way to indicate an error
    } else if (n == 0) {
        return 1;
    }

    // Hint 2: Loop from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Hint 3: Accumulate the product by multiplying the result by the loop counter
        result = result * i;
    }

    // Hint 4: Return the final product
    return result;
}

int main() {
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    long long fact = factorial(number);

    if (fact != -1) {
        std::cout << "The factorial of " << number << " is " << fact << std::endl;
    }

    return 0;
}

