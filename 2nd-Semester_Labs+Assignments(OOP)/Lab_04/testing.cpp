#include <iostream>
using namespace std;

int main(){
    std::string str1 = "HEllo";
    std::string str2 = "HEllO";

    
    if (str1 == str2) {
        // This block runs if the strings are identical
        std::cout << "Strings are equal!" << std::endl;
    } else {
        // This block runs if the strings are different
        std::cout << "Strings are not equal!" << std::endl;
    }
    return 0;

}