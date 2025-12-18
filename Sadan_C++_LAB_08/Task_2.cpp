// Task 2:  Function Overloading, Argument Promotion & Inline Function
#include <iostream>
using namespace std; 

inline int showSquare(int num){
    return(num * num);
}

float showSquare(float num){
    return(num * num);
}
int main(){
    
    //  inline function that accepts an int argument and returns its square.
    cout << showSquare(5) << endl;

    // second overloaded function that accepts a float argument and returns its square.
    cout << showSquare(3.7f) << endl;

    return 0;

}