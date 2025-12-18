#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Using input file stream
    ifstream carsFile;

    // Declaring variables
    int cars[10] = {0};
    int salesPerson = 0, carsSold = 0, totalCarsSold = 0, maxCarsSold = 0, topSalesPerson = 0;
    char colon = ' ';

    carsFile.open("cars.txt");

    // Checking is file opened or not
    if (!(carsFile.is_open()))
    {
        cout << "File can't be opened!" << endl;
        return 0;
    }

    // This will store data in array where salesPerson = array Index and carsSold = array value at that index
    while (carsFile >> salesPerson >> colon >> carsSold)
    {
        if (salesPerson >= 1 && salesPerson <= 10)
            cars[salesPerson - 1] = carsSold;
        else
            cerr << "Warning: invalid salesperson number " << salesPerson << " ignored.\n";
    }

    // Now reading data from array as per the task requirement
    for (int i = 0; i < 10; ++i)
    {
        totalCarsSold += cars[i];
        if (cars[i] > maxCarsSold)
        {
            maxCarsSold = cars[i];
            topSalesPerson = i + 1; // convert index -> salesperson number
        }
    }
    cout << endl
         << "Total number of cars sold are: " << totalCarsSold << endl;
    cout << "Salesperson " << topSalesPerson << " has sold maximum no. of cars: " << maxCarsSold << endl;

    carsFile.close();

    return 0;
}