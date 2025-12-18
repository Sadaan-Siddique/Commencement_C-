#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// For Data Reading
int mainReading()
{
    // ifstream takes input from the stream of file means read the file (stream is the input output channel through which data transfers in bits)
    ifstream readingFile("age.txt");

    // readingFile.open("age.txt");
    if (!(readingFile.is_open()))
    {
        cout << "File didn't open!" << endl;
        return 0;
    }
    cout << "Reading data: " << endl;
    string data;
    // readingFile >> data; will get only single word from file. It works same like cin. It'll stop at space bar

    // while (!readingFile.eof())
    // {
    //     getline(readingFile, data); // it'll get a string from file till \n comes and then save it in 'data'. Then this data will cout and loop will run again till the achievement of eof.
    //     cout << data << endl;
    // }
    while (!readingFile.eof())
    {
        // readingFile.get() basically returns integer (ASCII CODE) of every character. So we can either type cast it while doing cout or firstly store it in a character datatpe variable then cout it.
        cout << (char)readingFile.get(); // it will get a character each time along with \n then cout it then loop will run again till the achievemnt of eof
    }
    cout << (char)readingFile.get() << endl
         << "End of code!";

    readingFile.close();
    return 0;
}

// For Data writing
int main()
{
      // ofstream gives output to the stream of file means write in the file
    ofstream writingFile;

    char text;
    string info;
    int i = 0;

    writingFile.open("age.txt");

    if (!(writingFile.is_open()))
    {
        cout << "File didn't open!" << endl;
        return 0;
    }
    cout << "writing documents to file: " << endl;

    writingFile << "My first file creation.\n";
    writingFile << "File handling in C++.\n";
    writingFile << (char)getchar() << '\n'; // getchar() returns integer (ASCII CODE), so we have to type cast it or we can firstly store it in a character datatype variable then sent it to writingFile.
    getline(cin, info); // this will get a line till \n is achieved then store it in string variable.
    writingFile << info << '\n';
    do
    {
        // this loop will take a charater in every iteration from input buffer stream (typed by user)and store it in text varaible then sent it to writingFile(age.txt) then iterate the loop again for every character in input stream till the full stop '.' comes.
        text = getchar();
        writingFile << text;
        cout << i++ << endl;
    } while (text != '.');

    writingFile.close();

    return 0;
}