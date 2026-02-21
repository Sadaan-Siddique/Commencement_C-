#include <iostream>
using std::cout, std::cin, std::endl;

enum class EmployeeType
{
    manager,
    engineer,
    intern,
};

union Salary
{
    int monthlySalary;
    int hourlyWage;
};

struct Employee
{
    std::string name;
    EmployeeType type;
    Salary pay;
};

std::string getEmplyeeType(EmployeeType eType){
    switch(eType){
        case EmployeeType::manager : return "Manager";
        case EmployeeType::engineer : return "Engineer";
        case EmployeeType::intern : return "Intern";
        default: return "Anonymous Type";
    }
};


int main()
{
    Employee e1;

    cout << "Enter Employee name: ";
    std::getline(cin, e1.name);

    short int typeNum{0};
    cout << "\nEnter the Employee Type: \n 0-Manager\n 1-Engineer\n 2-Intern\n";
    cin >> typeNum;

    if (typeNum < 0 || typeNum > 2)
    {
        cout << "INVALD EMPLOYEE TYPE ENTERED!" << endl;
        return 0;
    }
    
    e1.type = static_cast<EmployeeType>(typeNum);

    switch (e1.type)
    {
    case EmployeeType::manager:
    case EmployeeType::engineer:
    {
        int salary{0};
        cout << "Enter monthly salary: ";
        std::cin >> salary;
        e1.pay.monthlySalary = salary;
    }
    break;
    case EmployeeType::intern:
    {
        int hourlyWage{0};
        cout << "Enter hourly wage: ";
        std::cin >> hourlyWage;
        e1.pay.hourlyWage = hourlyWage;
    }
    break;
    default:
    {
        cout << "INVALID EMPLOYEE TYPE!" << endl;
        return 0;
    }
    }

    cout << "Employee Info: "
         << "\n Name: " << e1.name
         << "\n Employee Type: " << getEmplyeeType(e1.type)
         << "\n Salary: " << (e1.type == EmployeeType::intern ? e1.pay.hourlyWage : e1.pay.monthlySalary)  
         << endl;

    return 0;
}