#include <iostream>
using std::cout, std::endl, std::cin;

class AccountHolder
{
private:
    std::string m_accountNumber{};
    std::string m_holderName{};
    long long m_holderBalance{};

public:
    void set_accountNumber(std::string accountNumber);
    const std::string& get_accountNumber() const;
    void set_holderName(std::string holderName);
    void set_holderBalance(long long holderBalance);
    const long long& get_holderBalance() const;
    void depositAmount(const long long& depositAmount);
    bool withdrawAmount(long long withdrawAmount);

};

void AccountHolder::set_accountNumber(std::string accountNumber){ m_accountNumber = accountNumber; }
const std::string& AccountHolder::get_accountNumber() const { return m_accountNumber; }
void AccountHolder::set_holderName(std::string holderName){ m_holderName = holderName; }
void AccountHolder::set_holderBalance(long long holderBalance){ m_holderBalance = holderBalance; }
const long long& AccountHolder::get_holderBalance() const { return m_holderBalance; }
void AccountHolder::depositAmount(const long long& depositAmount){ m_holderBalance+=depositAmount; }
bool AccountHolder::withdrawAmount(long long withdrawAmount)
{ 
    if (m_holderBalance >= withdrawAmount ) { m_holderBalance-=withdrawAmount; return true; }   
    else return false;
}

void depositingFunc(bool &isAllowed, AccountHolder* accountHolders, const int& size)
{
    bool hasDeposited = false;
    char yN = ' ';
    cout << "Want to deposit money? (Y/N): ";
    cin >> yN;
    switch (yN)
    {
    case 'Y':
    {
        for(int turn = 1; turn <= 3; turn++)
        {
            cout << "Enter Account Number: ";
            std::string accountNumber{};
            std::getline(cin, accountNumber);
            for(int i = 0 ; i < size ; i++)
            {
                if( ((accountHolders + i)->get_accountNumber()) == accountNumber )
                {
                    long long depositAmount {};
                    cout<<"Enter Deposit amount: ";
                    cin >> depositAmount;
                    (*(accountHolders + i)).depositAmount(depositAmount);
                    hasDeposited = true; // hasDeposited will tell this case Y loop whether the amount has been deposited or not
                    isAllowed = true; // isAllowed = true tells the main() that amount has been deposited
                }
                else if(i == (size - 1))
                {
                    cout<<"\n\033[31mWRONG ACCOUNT NUMBER!\033[0m\n\n";    
                    hasDeposited = false;
                }
            }
            if(hasDeposited) break;
        }    
    }
        break;
    case 'N':
         isAllowed = false;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; 
        isAllowed = true;
    }
}

int main()
{
    int size{2};
    AccountHolder accountHolders[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Accoutn Holder " << (i + 1) << " :";

        cout << "\n  Account Number: ";
        std::string accountNumber{};
        std::getline(cin, accountNumber);
        accountHolders[i].set_accountNumber(accountNumber);

        cout << "  Holder Name: ";
        std::string holderName{};
        std::getline(cin, holderName);
        accountHolders[i].set_holderName(holderName);

        cout << "  Account Balance: ";
        long long holderBalance{};
        cin >> holderBalance;
        accountHolders[i].set_holderBalance(holderBalance);

        cout << endl;
    }

    bool isAllowed = true;
    do
    {
        depositingFunc(isAllowed, accountHolders, size);
    } while (isAllowed);




    cout << "\n-----Displaying INFO-----\n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nStudent " << (i + 1) << " :";

        cout << "\n  Name: ";
        cout << (studentsPtr + i)->getName();

        cout << "\n  ID: ";
        cout << (studentsPtr + i)->getID();

        cout << "\n  Marks: \n";
        const double *marksPtr = (studentsPtr + i)->getMarks();
        for (int j = 0; j < 3; j++)
        {
            cout << "\tFor Subject " << (j + 1) << ": ";
            cout << *(marksPtr + j) << endl;
        }

        cout << "  Average Marks: " << (studentsPtr + i)->getAvgMarks() << endl;
        cout << "  Grade: " << (studentsPtr + i)->getGrade() << endl;
    }

    delete[] studentsPtr;
    studentsPtr = nullptr;

    return 0;
}