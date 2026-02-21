#include <iostream>
using std::cout, std::endl;

double addition(double a, double b) { return (a + b); }
double multiplication(double a, double b) { return (a * b); }

int main()
{
    double (*func)(double, double);

    double a = 0, b = 0;
    cout << "Enter two numbers: " << endl;
    std::cin >> a >> b;

    func = addition;
    cout << "Addition: "<< func(a, b) << endl;

    func = multiplication;
    cout << "Multiplication: "<< func(a, b) << endl;

    return 0;
}