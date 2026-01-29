#include <iostream>
#include <cmath> // for pow
#include <string>
using namespace std;

int main()
{

	int num = 0, sum = 0, remainder = 0, quotient = 1, save = 0, i;
	long long power = 1;

	cout << "Enter a number: ";
	cin >> num;
	if (num < 0)
		num = abs(num);
	save = num;
	remainder = num;
	for (; num >= 10;)
	{
		num = num / 10;
		power = power * 10;
	}
	cout << endl
		 << "The individual digits are: ";
	for (; remainder > 0;)
	{
		// quotient = remainder / pow(10, i);
		quotient = remainder / power;
		// save = save % pow(10, i);
		cout << quotient << " ";
		sum += quotient;
		// remainder = remainder % static_cast<long long>(pow(10, i));
		remainder = remainder % power;
		power = power / 10;
	}
	cout << endl
		 << "Sum of individual digits of " + to_string(save) + " is: " << sum << endl
		 << endl;

	return 0;
}
