#include <iostream>
using std::cout, std::cin, std::endl;

/*
---------------------------------------
1) Create an enum for Employee Type
---------------------------------------
This enum represents the category of employee.
We use enum class for type-safety.
*/
enum class EmployeeType
{
    manager,   // Manager employee
    engineer,  // Engineer employee
    intern     // Intern employee
};

/*
---------------------------------------
2) Create a union Salary
---------------------------------------
Union stores only ONE value at a time.
Either monthlySalary OR hourlyWage.
Both share the same memory location.
*/
union Salary
{
    int monthlySalary; // For Manager & Engineer
    int hourlyWage;    // For Intern
};

/*
---------------------------------------
3) Create a struct Employee
---------------------------------------
This structure stores complete employee data:
- name  → employee name
- type  → employee category (EmployeeType)
- pay   → salary info (union Salary)
*/
struct Employee
{
    std::string name;   // Employee name
    EmployeeType type;  // Employee type (Manager/Engineer/Intern)
    Salary pay;         // Salary data (monthly or hourly)
};

/*
---------------------------------------
Helper function to convert enum to string
---------------------------------------
This function converts EmployeeType enum
into readable text for display purposes.
*/
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
    // Create an Employee object
    Employee e1;

    // Ask user for employee name
    cout << "Enter Employee name: ";
    std::getline(cin, e1.name);

    // Ask user for employee type
    short int typeNum{0};
    cout << "\nEnter the Employee Type: \n 0-Manager\n 1-Engineer\n 2-Intern\n";
    cin >> typeNum;

    // Validate employee type input
    if (typeNum < 0 || typeNum > 2)
    {
        cout << "INVALD EMPLOYEE TYPE ENTERED!" << endl;
        return 0;
    }
    
    // Convert integer input to EmployeeType enum
    e1.type = static_cast<EmployeeType>(typeNum);

    /*
    ---------------------------------------
    Salary input based on employee type
    ---------------------------------------
    If Manager or Engineer → monthly salary
    If Intern → hourly wage
    */
    switch (e1.type)
    {
    case EmployeeType::manager:
    case EmployeeType::engineer:
    {
        // Input monthly salary
        int salary{0};
        cout << "Enter monthly salary: ";
        std::cin >> salary;
        e1.pay.monthlySalary = salary;  // Store in union
    }
    break;

    case EmployeeType::intern:
    {
        // Input hourly wage
        int hourlyWage{0};
        cout << "Enter hourly wage: ";
        std::cin >> hourlyWage;
        e1.pay.hourlyWage = hourlyWage; // Store in union
    }
    break;

    default:
    {
        cout << "INVALID EMPLOYEE TYPE!" << endl;
        return 0;
    }
    }

    /*
    ---------------------------------------
    Display Employee Information
    ---------------------------------------
    If Intern → show hourly wage
    Else → show monthly salary
    */
    cout << "Employee Info: "
         << "\n Name: " << e1.name
         << "\n Employee Type: " << getEmplyeeType(e1.type)
         << "\n Salary: " 
         << (e1.type == EmployeeType::intern 
                ? e1.pay.hourlyWage      // Intern salary
                : e1.pay.monthlySalary)  // Manager/Engineer salary
         << endl;

    return 0;
}
