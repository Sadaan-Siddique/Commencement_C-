#include <iostream>
using namespace std;

int main_int(){
	try {
		int numerator = 0, denumerator = 0;
		
		cout<<"Enter numerator: ";
		cin>>numerator;
		
		cout<<"Enter denumerator: ";
		cin>>denumerator;
		
		if(denumerator==0){
			throw 400;
			
		}
		cout<<"Division: "<<numerator/denumerator<<endl;
	}
	catch(int value){
		cout<<"Invalid Input. Anything divided by zero is undefined.";
	}
	return 0;
}


int main(){
	try {
		int numerator = 0, denumerator = 0;
		
		cout<<"Enter numerator: ";
		cin>>numerator;
		
		cout<<"Enter denumerator: ";
		cin>>denumerator;
		
		if(denumerator==0){
			throw string('Not defined');
			
		}
		cout<<"Division: "<<numerator/denumerator<<endl;
	}
	catch(string * error){
		cout<<error";
	}
	return 0;
}
