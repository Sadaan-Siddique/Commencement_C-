#include <iostream>
using std::cout, std::cin, std::endl;

struct Date
{
    int day;
    int month;
    int year;
};

struct Employee
{
    int rollNo;
    std::string name;
    double marks;
    Date dOfB;
};

int main()
{
    Employee s1 = {2025611, "Sadaan", 97, {30, 11, 2006}}, s2 = {2025011, "Ahad", 87, {16, 01, 2006}}, s3 = {2025111, "Talha", 55, {24, 04, 2006}}, *p1 = &s1, *p2 = &s2, *p3 = &s3;

    cout << "Roll number: " << p1->rollNo << ". Name: " << p1->name << ". Marks: " << p1->marks << ". Date of Birth: " << p1->dOfB.day << " " << p1->dOfB.month << " " << p1->dOfB.year << endl;

    cout << "Roll number: " << p2->rollNo << ". Name: " << p2->name << ". Marks: " << p2->marks << ". Date of Birth: " << p2->dOfB.day << " " << p2->dOfB.month << " " << p2->dOfB.year << endl;

    cout << "Roll number: " << p3->rollNo << ". Name: " << p3->name << ". Marks: " << p3->marks << ". Date of Birth: " << p3->dOfB.day << " " << p3->dOfB.month << " " << p3->dOfB.year << endl;

    cout << "Average Marks: " << (p1->marks + p2->marks + p3->marks) / 3 << endl;

    return 0;
}