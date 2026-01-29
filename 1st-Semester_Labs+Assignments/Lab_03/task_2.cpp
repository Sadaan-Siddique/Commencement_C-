#include <iostream>
#include <string>
using namespace std;

int main(){
	int temperature,temp_fahren;
	cout<<"Enter your surrounding temperature in Celsius : ";
	cin>>temperature;
	temp_fahren = ((9.0/5.0)*temperature) + 32;
//	temp_fahren = ((static_cast<float>(9) / 5) * temperature) + 32;
	if (temperature==0){
		cout<<temp_fahren<<" fahrenheit is the melting point or freeezing point of water."<<endl;
	}else if(temperature > 0 && temperature <= 15){
		cout<<temp_fahren<<" fahrenheit it's cold!"<<endl;
	}else if(temperature >15 && temperature <=30){
		cout<<temp_fahren<<" fahrenheit it's moderate!"<<endl;
	}else if(temperature > 30){
		cout<<temp_fahren<<" fahrenheit it's hot!"<<endl;
	}else{
		cout<<temp_fahren<<" fahrenheit it's very cold!"<<endl;
	}
	return 0;
}
