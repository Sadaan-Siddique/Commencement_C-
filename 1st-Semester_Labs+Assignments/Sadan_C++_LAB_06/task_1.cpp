#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	while (true)
	// This program will run continuously until you press ctrl+C
	{
		try
		{
			long long balance = 0, amount = 0;
			int select = 0;

			cout << "Enter your initial account balance: ";
			cin >> balance;

			cout << "What operation do you want: \n 1.withdraw \n 2.Deposit \n 3.Check Balance \n Select: ";
			cin >> select;

			switch (select)
			{
			case 1:
			{
				cout << "Amount to withdraw: ";
				cin >> amount;
				if (amount > balance || amount < 0)
					throw runtime_error("Insufficient balance for withdrawal.");
				cout << "Your amount has successfully been withdrawal. \n Your new current amount is: " << balance - amount;
				break;
			}
			case 2:
			{
				cout << "Enter the Deposit amount: ";
				cin >> amount;
				if (amount <= 0)
					throw invalid_argument("Deposit amount must be greater than zero.");
				cout << "Amount has been deposited successfully. \n Your new current amount is: " << balance + amount;
				break;
			}
			case 3:
			{
				cout << "Your current balance is: " << balance;
				break;
			}

			default:
			{
				throw "Invalid menu option selected.";
				break;
			}
			}
		}
		catch (const exception &e)
		{
			cout << "Error: " << e.what() << endl;
		}

		catch (const char *error)
		{
			cout << "Meassage: " << error << endl;
		}
		cout << "\n\n ___________ \n\n";
	}
	return 0;
}
