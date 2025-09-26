#include <iostream>
#include <string>
using namespace std;

// This program is about : to calculate an electricity bill based on the following:
// • Rates:
// ▪ First 100 units → Rs. 10/unit o Next 200 units → Rs. 15/unit
// ▪ Above 300 units → Rs. 20/unit
// • Add a 10% surcharge if total units exceed 400.
// • Add a late fee of Rs. 500 if payment is delayed (user provides a boolean input).
// • Use nested if–else for tiered calculations and a switch to handle late payment confirmation (Yes/No).

int main()
{
  int units, bill;
  bool delayed;
  cout << "Enter your bill units : ";
  cin >> units;

  if (units > 0)
  {

    cout << "Is your payment delayed? (Be honest) 'Yes = 1/ No = 0' : ";
    cin >> delayed;
    cout << delayed << endl;

    if (units <= 100)
    {
      bill = units * 10;
      switch (delayed)
      {
      case true:
        cout << "Your Bill with late payment submission is : " << bill + 500 << endl;
        break;
      case false:
        cout << "Your Bill is : " << bill << endl;
        break;
      default:
        cout << "Write either 1 or 0 .";
        break;
      }
    }
    else if (units > 100 && units <= 300)
    {
      bill = 100 * 10 + (units - 100) * 15;
      switch (delayed)
      {
      case true:
        cout << "Your Bill with late payment submission is : " << bill + 500 << endl;
        break;
      case false:
        cout << "Your Bill is : " << bill << endl;
        break;
      default:
        cout << "Write either 1 or 0 .";
        break;
      }
    }
    else if (units > 300)
    {
      if (units > 400)
      {
        bill = 100 * 10 + 200 * 15 + (units - 300) * 20;
        switch (delayed)
        {
        case true:
          cout << "Your Bill with surcharges and late payment submission is : " << 0.10 * bill + bill + 500 << endl;
          break;
        case false:
          cout << "Your Bill with surcharges is : " << 0.1 * bill + bill << endl;
          break;
        default:
          cout << "Write either 1 or 0 .";
          break;
        }
      }
      else
      {
        bill = 100 * 10 + 200 * 15 + (units - 300) * 20;
        switch (delayed)
        {
        case true:
          cout << "Your Bill with late payment submission is : " << bill + 500 << endl;
          break;
        case false:
          cout << "Your Bill is : " << bill << endl;
          break;
        default:
          cout << "Write either 1 or 0 .";
          break;
        }
      }
    }
  }
  else if (units == 0)
  {
    cout << "Invalid Input." << endl;
  }
  else if (units < 0)
  {
    cout << "Invalid Input. Units must be positive." << endl;
  }
  return 0;
}
