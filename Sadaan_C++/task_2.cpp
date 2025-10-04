#include <iostream>
using namespace std;

int main(){
	int i = 1, print=1,loops;
	
	cout<<"Enter the number of lines of triangle you want : ";
	cin>>loops;
	
	while(i<=loops){
		while(i>=print){
		cout<<"*";	
		print++;
		}
		cout<<endl;
		print=1;
		i++;
	}
}
