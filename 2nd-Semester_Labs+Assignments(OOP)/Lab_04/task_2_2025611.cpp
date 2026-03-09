#include <iostream>
#include <limits>
using std::cout, std::endl, std::cin;

class AccountHolder
{
private:
    std::string m_accountNumber{}; // an account number may have alphabets along with integers
    std::string m_holderName{};
    long long m_holderBalance{};

public:
    void set_accountNumber(std::string accountNumber);
    const std::string& get_accountNumber() const;

    void set_holderName(std::string holderName);
    const std::string& get_holderName() const;

    void set_holderBalance(long long holderBalance);
    const long long& get_holderBalance() const;

    void depositAmount(const long long& depositAmount);
    bool withdrawalAmount(long long withdrawalAmount);

};

void AccountHolder::set_accountNumber(std::string accountNumber){ m_accountNumber = accountNumber; }
const std::string& AccountHolder::get_accountNumber() const { return m_accountNumber; }

void AccountHolder::set_holderName(std::string holderName){ m_holderName = holderName; }
const std::string& AccountHolder::get_holderName() const { return m_holderName; }

void AccountHolder::set_holderBalance(long long holderBalance){ m_holderBalance = holderBalance; }
const long long& AccountHolder::get_holderBalance() const { return m_holderBalance; }

void AccountHolder::depositAmount(const long long& depositAmount){ m_holderBalance+=depositAmount; }
bool AccountHolder::withdrawalAmount(long long withdrawalAmount)
{ 
    if (m_holderBalance >= withdrawalAmount ) { m_holderBalance-=withdrawalAmount; return true; }   
    else return false;
}

void depositingFunc(bool &isAllowed, AccountHolder* accountHolders, const int& size)
{
    bool hasDeposited = false; // hasDeposited will tell this ' case Y ' loop whether the amount has been deposited or not
    char yN = ' ';
    cout << "\nWant to deposit money? (Y/N): ";
    cin >> yN;
    switch (yN) // enter Y for yes and N for no
    {
    case 'Y':
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for(int turn = 1; turn <= 3; turn++)
        {
            cout << "Enter Account Number: "; // you can type account number of any of the account holder, it is not necessary to write in order the account number of the account holders
            std::string accountNumber{};
            std::getline(cin, accountNumber); // if you type wrong account number 3 times, you will be exited from this function without being entertained
            for(int i = 0 ; i < size ; i++) // this loop is for comparing the entered account number with each account holder's account number
            {
                AccountHolder& accountHolder = *(accountHolders + i);
                if( (accountHolder.get_accountNumber()) == accountNumber )
                {
                    long long depositAmount {};
                    cout<<"Dear "<<accountHolder.get_holderName()<<", Enter Deposit amount: ";
                    cin >> depositAmount;
                    accountHolder.depositAmount(depositAmount);
                    hasDeposited = true; 
                    isAllowed = true; // isAllowed = true tells the main() that amount has been deposited
                    cout<<accountHolder.get_holderName()<<", your current balance is: "<<accountHolder.get_holderBalance()<<endl;
                    break;    
                }
                else if(i == (size - 1)) // this will pop up a message to indicate that the entered account number is not valid.
                    cout<<"\n\033[31mWRONG ACCOUNT NUMBER!\033[0m\nYou've "<<(3 - turn)<<" turns left!\n";    
            }
            if(hasDeposited) break; // if the deposition process is successful, this will break the loop and get you back to the main function
            for(int i = 0; i < 1000000000; i++);
        }    
    }
        break;
    case 'N':
         isAllowed = false;
         break;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; 
        isAllowed = true;
    }
}

void withdrawalFunc(bool &isAllowed, AccountHolder* accountHolders, const int& size)
{
    bool hasWithdrawal = false; // hasDeposited will tell this ' case Y ' loop whether the amount has been deposited or not
    char yN = ' ';
    cout << "\nWant to Withdraw money? (Y/N): ";
    cin >> yN;
    switch (yN)
    {
    case 'Y':
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for(int turn = 1; turn <= 3; turn++)
        {
            cout << "Enter Account Number: ";
            std::string accountNumber{};
            std::getline(cin, accountNumber);
            for(int i = 0 ; i < size ; i++)
            {
                AccountHolder& accountHolder = *(accountHolders + i);
                if( (accountHolder.get_accountNumber()) == accountNumber )
                {
                    long long withdrawalAmount {};
                    cout<<"Dear "<<accountHolder.get_holderName()<<", Enter withdrawal amount: ";
                    cin >> withdrawalAmount;
                    if( accountHolder.withdrawalAmount(withdrawalAmount) ) // if the withdrawalFunction returns true, means that the entered withdrawal amount is less than the current account balance
                    {
                        hasWithdrawal = true; 
                        isAllowed = true; // isAllowed = true tells the main() that amount has been deposited
                        cout<<accountHolder.get_holderName()<<", your current balance is: "<<accountHolder.get_holderBalance()<<endl;  
                    }else {
                        cout<<"Dear "<<accountHolder.get_holderName()<<", you have not sufficient balance to withdraw!\n";
                        isAllowed = true;
                    }
                    break;    
                }
                else if(i == (size - 1))
                    cout<<"\n\033[31mWRONG ACCOUNT NUMBER!\033[0m\nYou've "<<(3 - turn)<<" turns left!\n\n";    
            }
            if(hasWithdrawal || isAllowed) break;
            for(int i = 0; i < 1000000000; i++);
        }    
    }
        break;
    case 'N':
         isAllowed = false;
         break;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; 
        isAllowed = true;
    }
}

int main()
{
    int size{2};
    AccountHolder accountHolders[size]; // forming an array to hold two account holders' class objects, you can resize it

    for (int i = 0; i < size; i++)
    {
        bool isExist = false;
        cout << "Account Holder " << (i + 1) << " :";

        // Account Number
        cout << "\n  Enter Account Number: ";
        std::string accountNumber{};
        std::getline(cin, accountNumber);
        if(i > 0) // this if statement checks whether two accounts have same account number or not
            for(int j = 0; j < i; j++)
                if((accountHolders + j)->get_accountNumber() == accountNumber)
                    { 
                        cout<<"\n\033[31mACCOUNT NUMBER ALREADY EXISTS!\033[0m\n"<<endl;
                        isExist = true; 
                    }
        if(isExist) { i--; continue; }
        accountHolders[i].set_accountNumber(accountNumber);

        // Holder Name
        cout << "  Enter Holder Name: ";
        std::string holderName{};
        std::getline(cin, holderName);
        accountHolders[i].set_holderName(holderName);

        // Holder Balance
        cout << "  Enter Account Balance (in PKR): ";
        long long holderBalance{};
        cin >> holderBalance;
        accountHolders[i].set_holderBalance(holderBalance);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;
    }

    bool isAllowed = false;
    do
    {
        depositingFunc(isAllowed, accountHolders, size); // function to deposit money in bank account
        if(!isAllowed) // if isAllowed is false, then this means deposition didn't processed
        {
            for(int i = 0; i < 999000000; i++); // loop for delay
            cout<<"\nYour Amount Deposition didn't processed.\n";
        }    

        isAllowed = false; // again falsing isAllowed to work properly for withdrawing function
        for(int i = 0; i < 1000000000; i++);

        withdrawalFunc(isAllowed, accountHolders, size); // function to withdraw money from bank account
        if(!isAllowed)
        {
            for(int i = 0; i < 999000000; i++);
            cout<<"\nYour Amount withdrawing didn't processed.\n";
        } 

        for(int i = 0; i < 1000000000; i++);
        // if you press 'N' for withdrawal function or enter wrong account number 3 times for withdrawal function, you'll be exited from loop
    } while (isAllowed);

    cout << "\n-----Displaying INFO-----\n";
    // this loop will display the information of the account holders' class objects
    for (int i = 0; i < size; i++)
    {
        cout << "\nDear " <<accountHolders[i].get_holderName()<<", your ";
        cout << "\n  Account Number is: "<<accountHolders[i].get_accountNumber();
        cout << "\n  Current Account Balance is: "<<accountHolders[i].get_holderBalance()<<endl;
    }

    return 0;
}