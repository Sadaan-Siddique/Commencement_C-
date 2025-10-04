#include <iostream>
using namespace std;

int main_2();
int main_1();
int main()
{
	int i = 1, row_elements = 1;
	while (row_elements < 5)
	{
		while (i < 6)
		{
			cout << "+ ";
			i++;
		}
		cout << endl;
		i -= 5;
		row_elements++;
	}
	cout << "Before calling main_2()\n";
	main_2();
	cout << "Returned from main_2()\n";
	cout << "hello";
	cout << "Before calling main_1()\n";
	main_1();
	cout << "Returned from main_1()\n";
	return 0;
}

int main_2()
{
	int i = 1;
	cout << "Hello World" << endl;
	while (i <= 25)
	{
		while (i < 6)
		{
			cout << "= ";
			i++;
		}
		cout << endl;
		while (i > 5 && i <= 10)
		{
			cout << "= ";
			i++;
		}
		cout << endl;
		while (i > 10 && i <= 15)
		{
			cout << "= ";
			i++;
		}
		cout << endl;
		while (i > 15 && i <= 20)
		{
			cout << "= ";
			i++;
		}
		cout << endl;
		while (i > 20 && i <= 25)
		{
			cout << "= ";
			i++;
		}
		cout << endl;
	}
	return 0;
}

int main_1()
{

	int i = 10;
	while (i > 0)
	{
		cout << i << endl;
		i--;
	}
	return 0;
}
