#include <iostream>
using namespace std;

int main_1() {
    int num;
    cout << "Enter an integer: ";
    if (cin >> num) {
        cout << "You entered integer: " << num << endl;
    } else {
        cout << "That's not an integer!" << endl;
    }
    return 0;
}


// A function for calculating whether the input number is divisible by eight or not
int main_2(){
	int num;
	cout<<"Please Enter a positive Integer : ";
	cin>>num;
	if(num%8==0){
		cout<<num<<" is divisible by eight, four and two"<<endl;
	}else{
		cout<<num<<" is not divisible by eight, four and two"<<endl;
	}
	return 0;
}
