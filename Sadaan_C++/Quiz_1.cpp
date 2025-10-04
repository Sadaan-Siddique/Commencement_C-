#include <iostream>
using namespace std;

int main(){
	 int A = 0;
     cout << "Write your amount in Rupees : Rs.";
     cin >> A;
     if (A == 0 || A < 0)
     {
         cout << "Amount must be a positive integer." << endl;
         return 0;
     }

     cout << "Your amount equivalent to currency notes is : " << endl;
     cout << "5000 : " << A / 5000 << endl;
     cout << "1000 : " << (A % 5000) / 1000 << endl;
     cout << "500 : " << ((A % 5000) % 1000) / 500 << endl;
     cout << "100 : " << (((A % 5000) % 1000) % 500) / 100 << endl;
     cout << "50 : " << ((((A % 5000) % 1000) % 500) % 100) / 50 << endl;
     cout << "10 : " << (((((A % 5000) % 1000) % 500) % 100) % 50) / 10 << endl;
     cout << "5 : " << ((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) / 5 << endl;
     cout << "2 : " << (((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) % 5) / 2 << endl;
     cout << "1 : " << ((((((((A % 5000) % 1000) % 500) % 100) % 50) % 10) % 5) % 2) / 1 << endl;
     return 0;
}


    
