#include <iostream>
#include <string>
using namespace std;

//Task to Develop a program to check whether a given year is a leap year or not
//
//int main() {
//    int year;
//    cout << "Enter any Year: ";
//    
//    if (cin >> year) {
//        if (year < 0) {
//            cout << "Invalid Input. Year must be positive." << endl;
//        } else {
//            if (year % 4 == 0) {
//                if (year % 100 == 0) {
//                    if (year % 400 == 0) {
//                        cout << year << " is a leap year." << endl;
//                    } else {
//                        cout << year << " is not a leap year." << endl;
//                    }
//                } else {
//                    cout << year << " is a leap year." << endl;
//                }
//            } else {
//                cout << year << " is not a leap year." << endl;
//            }
//        }
//    } else {
//        cout << "Enter an Integer." << endl;
//    }
//
//    return 0;
//}
int main()
{
    int year;
    cout << "Enter any Year : ";
    cin >> year;
    if (year < 0)
    {
        cout << "Invalid Input. Year must be positive." << endl;
    }
    else if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }
    return 0;
}

