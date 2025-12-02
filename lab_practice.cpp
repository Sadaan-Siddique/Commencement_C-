#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void square(int num, int *ptr2)
{
	int *ptr = &num;
	*ptr2 = 50;
	cout << "square: " << num * num << endl
		 << "Pointer1: " << ptr << endl
		 << "Pointer2: " << ptr2 << endl;
}

int main()
{
	int num = 0, num2 = 0;
	cout << "Enter any integer: ";
	cin >> num;
	square(num, &num2);
	cout << "Inside main(): num: " << num << endl
		 << " num2: " << num2 << endl;

	// int *fruitPointer;
	// fruitPointer = apples;	// ❌ ERROR: 'apples' is just the number 5. Pointers need addresses!
	// fruitPointer = &apples; // ✅ CORRECT: '&apples' is the address say ' 1024 ' .
	int *ptr = &num;
	cout << "Pointer: " << ptr << "\nnum2: " << &num2 << endl;
	return 0;
}

int main_1()
{
	int num;
	cout << "Enter an integer: ";
	if (cin >> num)
	{
		cout << "You entered integer: " << num << endl;
	}
	else
	{
		cout << "That's not an integer!" << endl;
	}
	return 0;
}

// A function for calculating whether the input number is divisible by eight or not
int main_2()
{
	int num;
	cout << "Please Enter a positive Integer : ";
	cin >> num;
	if (num % 8 == 0)
	{
		cout << num << " is divisible by eight, four and two" << endl;
	}
	else
	{
		cout << num << " is not divisible by eight, four and two" << endl;
	}
	return 0;
}
