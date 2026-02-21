#include <iostream>
using std::cout, std::endl;

double addition(double a, double b){ return (a + b);}
double multiplication(double a, double b){ return (a * b);}

int main(){
    double (*funcs[2])(double a, double b) = {addition, multiplication};

    double a = 0, b = 0;
    cout<<"Enter two numbers: "<<endl;
    std::cin >> a >> b;

    cout<<"Addition: "<<endl;
    cout<<funcs[0](a,b)<<endl;

    cout<<"Multiplication: "<<endl;
    cout<<funcs[1](a,b)<<endl;

    return 0;
}