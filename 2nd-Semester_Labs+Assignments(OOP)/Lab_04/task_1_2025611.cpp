#include <iostream>
#include <limits>
using std::cout, std::endl, std::cin;

class Student 
{
    private:
        std::string m_name {};
        int m_ID {};
        double m_marks[3] = {};
        double m_avgMarks {};

    public:
        const std::string& getName() const { return m_name; }
        void setName(std::string name) { m_name = name; }
        const int& getID() const { return m_ID; }
        void setId(int ID) { m_ID = ID; }
        const double* getMarks() const { return m_marks; }
        void setMarks(double marks, int index) 
        {
            m_marks[index] = marks; 
            for(const double &element : m_marks)  m_avgMarks += element;
            m_avgMarks /= 3;
         }
        
        const double& getAvgMarks() const { return m_avgMarks;}

};

// this function will ask from user to either enter more marks or not
void addStdFunc(int &size)
{
    char yN = ' ';
    int additionalStds{};
    cout << "Want to add more Students? (Y/N): ";
    cin >> yN;
    switch (yN)
    {
    case 'Y':
        cout << "Enter number of additional students: ";
        cin >> additionalStds;
        size += additionalStds;
        break;
    case 'N':
        return;
    default:
        cout << "\n\033[31mINVALID COMMAND!\033[0m\n\n"; // to handle invalid commands entered
        addStdFunc(size); // I have used recursion to again ask from user. It'll not affect my code
    }
    return;
}

int main()
{
    int size{2};
    Student *studentsPtr = new Student[size]; // creating an array for two objects of Student class

    for(int i = 0; i < size; i++)
    {
        cout<<"Student "<< (i + 1) <<" :";

        cout<<"\n  Name: ";
        std::string name {};
        std::getline(cin, name);
        (*(studentsPtr + i)).setName(name);

        cout<<"  ID: ";
        int id {};
        cin >> id;
        (*(studentsPtr + i)).setId(id);

        cout<<"  Marks: \n";
        double marks {};
        for(int j = 0; j < 3; j++){
            cout<<"\tFor Subject "<< (j + 1) << ": ";
            cin >> marks;
            (*(studentsPtr + i)).setMarks(marks, j);
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (i == (size - 1)) // when i is equal to n - 1, then this will take confirmity from user to either end the loop or not
            addStdFunc(size);
        cout<<endl;
    }    

    cout<<"\n-----Displaying INFO-----\n";

    for(int i = 0; i < 2; i++)
    {
        cout<<"\nStudent "<< (i + 1) <<" :";

        cout<<"\n  Name: ";
        cout << (studentsPtr+ i)->getName();

        cout<<"\n  ID: ";
        cout << (studentsPtr + i)->getID();

        cout<<"\n  Marks: \n";
        const double *marksPtr = (studentsPtr + i)->getMarks();
        for(int j = 0; j < 3; j++){
            cout<<"\tFor Subject "<< (j + 1) << ": ";
            cout << *(marksPtr + j) << endl;
        }

        cout<<"  Average Marks: "<<(studentsPtr + i)->getAvgMarks()<<endl;
    }

    delete[] studentsPtr;
    studentsPtr = nullptr;

    return 0;
    
}