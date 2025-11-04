#include <iostream>
using namespace std;

int main()
{
	int num = 0, power = 1, quotient = 0, remainder = 0, sum = 0;
	cout << "Enter any positive number: ";
	cin >> num;
	for (int i = num; i > 0;)
	{
		i /= 10;
		power *= 10;
	}
	cout << power << endl;
	for (int i = num; i > 0;)
	{
		power /= 10;
		quotient = i / power;
		i %= power;
		sum += quotient;
		cout << quotient << " \n";
	}
	cout << sum;
	return 0;
}
