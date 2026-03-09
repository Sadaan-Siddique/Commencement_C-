    #include <iostream>
    #include <limits>
    using std::cout, std::endl, std::cin;

    class Student 
    {
        private: // m_ is used to distinguish class member variabels from outside local or gloabal variables
            std::string m_name {};
            int m_ID {};
            double m_marks[3] = {}; // a static array to store the marks of 3 subjects
            double m_avgMarks {};
            char m_grade {};

        public:
            const std::string& get_name() const { return m_name; }
            void set_name(std::string name) { m_name = name; }

            const int& get_ID() const { return m_ID; }
            void set_ID(int ID) { m_ID = ID; }

            const double* get_marks() const { return m_marks; }
            void set_marks(double marks, int index) 
            {
                m_marks[index] = marks; 
                if(index < 2) return; // this if condition ensures that the below code will run only for the last index to do necessary calculations
                m_avgMarks = 0;
                for(const double &element : m_marks)  m_avgMarks += element; // range based for loop to run it over m_marks array
                m_avgMarks /= 3;
                if (m_avgMarks >= 90 ) m_grade = 'A'; // this small if else is for grading a student based on average marks
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
        Student *studentsPtr = new Student[size]; // creating an array for 'size' objects of Student class on heap to make the flow dynamic
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for(int i = 0; i < size; i++)
        {
            bool isExist = false;
            cout<<"Student "<< (i + 1) <<" :";
            // Name
            cout<<"\n  Name: ";
            std::string name {};
            std::getline(cin, name); // to take the spaces between first name and last name
            (*(studentsPtr + i)).set_name(name);
            //ID
            cout<<"  ID: ";
            int id {};
            cin >> id;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(i > 0) // this will check whether the entered ID also own by any other student or not
                for(int j = 0; j < i; j++)
                    if((studentsPtr + j)->get_ID() == id)
                    { 
                        cout<<"\n\033[31mA User Name with this ID ALREADY EXISTS!\033[0m\n"<<endl;
                        isExist = true; 
                    }
            if(isExist) { i--; continue; } // this will reduce i and continue the current iteration to again call for name and ID
            (*(studentsPtr + i)).set_ID(id);
            // Marks
            cout<<"  Marks: \n";
            double marks {};
            for(int j = 0; j < 3; j++){ // this loop will take marks for 3 subjects
                cout<<"\tFor Subject "<< (j + 1) << ": ";
                cin >> marks;
                (*(studentsPtr + i)).set_marks(marks, j);
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<endl;
        }    

        for(int i = 0; i < 1000000000; i++); // loop for delay
        cout<<"\n-----Displaying INFO-----\n";
        for(int i = 0; i < 1000000000; i++);

        for(int i = 0; i < size; i++) // this loop will display the info of all the student objects on heap
        {
            cout<<"\nStudent "<< (i + 1) <<" :";
            // Name
            cout<<"\n  Name: ";
            cout << (studentsPtr+ i)->get_name();
            // ID
            cout<<"\n  ID: ";
            cout << (studentsPtr + i)->get_ID();
            // Marks
            cout<<"\n  Marks: \n";
            const double *marksPtr = (studentsPtr + i)->get_marks();
            for(int j = 0; j < 3; j++){ // displaying the marks for all 3 subjects
                cout<<"\tFor Subject "<< (j + 1) << ": ";
                cout << *(marksPtr + j) << endl;
            }

            cout<<"  Average Marks: "<<(studentsPtr + i)->get_avgMarks()<<endl; // average marks
            cout<<"  Grade: "<<(studentsPtr + i)->get_grade()<<endl; // grade of student based on average marks

        }

        delete[] studentsPtr;
        studentsPtr = nullptr;

        return 0;
        
    }