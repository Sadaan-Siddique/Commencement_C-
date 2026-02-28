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
            char m_grade {};

        public:
            const std::string& get_name() const { return m_name; }
            void set_name(std::string name) { m_name = name; }
            const int& get_ID() const { return m_ID; }
            void set_Id(int ID) { m_ID = ID; }
            const double* get_marks() const { return m_marks; }
            void set_marks(double marks, int index) 
            {
                m_marks[index] = marks; 
                m_avgMarks = 0;
                for(const double &element : m_marks)  m_avgMarks += element;
                m_avgMarks /= 3;

                if (m_avgMarks >= 90 ) m_grade = 'A';
                else if (m_avgMarks >= 80 ) m_grade = 'B';
                else if (m_avgMarks >= 65 ) m_grade = 'C';
                else if (m_avgMarks >= 50 ) m_grade = 'D';
                else if (m_avgMarks < 50 ) m_grade = 'F';
            }
            
            const double& get_avgMarks() const { return m_avgMarks; }
            const char& get_grade() const { return m_grade; }
    };

    int main()
    {
        int size{2};
        cout << "Enter number of students: ";
        cin >> size;
        Student *studentsPtr = new Student[size]; // creating an array for two objects of Student class
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for(int i = 0; i < size; i++)
        {
            cout<<"Student "<< (i + 1) <<" :";

            cout<<"\n  Name: ";
            std::string name {};
            std::getline(cin, name);
            (*(studentsPtr + i)).set_name(name);

            cout<<"  ID: ";
            int id {};
            cin >> id;
            (*(studentsPtr + i)).set_Id(id);

            cout<<"  Marks: \n";
            double marks {};
            for(int j = 0; j < 3; j++){
                cout<<"\tFor Subject "<< (j + 1) << ": ";
                cin >> marks;
                (*(studentsPtr + i)).set_marks(marks, j);
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<endl;
        }    

        cout<<"\n-----Displaying INFO-----\n";

        for(int i = 0; i < size; i++)
        {
            cout<<"\nStudent "<< (i + 1) <<" :";

            cout<<"\n  Name: ";
            cout << (studentsPtr+ i)->get_name();

            cout<<"\n  ID: ";
            cout << (studentsPtr + i)->get_ID();

            cout<<"\n  Marks: \n";
            const double *marksPtr = (studentsPtr + i)->get_marks();
            for(int j = 0; j < 3; j++){
                cout<<"\tFor Subject "<< (j + 1) << ": ";
                cout << *(marksPtr + j) << endl;
            }

            cout<<"  Average Marks: "<<(studentsPtr + i)->get_avgMarks()<<endl;
            cout<<"  Grade: "<<(studentsPtr + i)->get_grade()<<endl;

        }

        delete[] studentsPtr;
        studentsPtr = nullptr;

        return 0;
        
    }