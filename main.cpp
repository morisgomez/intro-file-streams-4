//tutorial followed: https://youtu.be/degQs6M5Igg
#include <string>
#include <iostream>
#include <fstream> //library that helps us work with streams. allows us to read from files and write to files.
//fstream has data types: fstream for both reading and writing, ifstream for reading input and osfstream for writing output.
using namespace std;

//PASSING FILE STREAM OBJECTS TO FUNCTIONS

//function: closes the file
void closeFile (ifstream& fin)
{
    fin.close();
}

//function: prints values from txt file in console
void printData (ifstream& fin)
{
    int x; //var is created with function scope only.
    while (fin >> x)
    {
        cout << x << endl;
    }
}

//opens file and verifies if it was opened
bool openFile (string fileStringCopy, ifstream& fin)
{
    fin.open(fileStringCopy); //opens file and associates file with fin ifstream type.
    if (fin.is_open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    //open and verify:
    ifstream fin;
    string fileString = "hankTutorial.txt";
    bool openVerification = openFile(fileString, fin);
    //we need to pass the file as a string and the ifstream variable fin.
    //in this function, we associate these two. fin is a reference, so any changes in function will happen to original.


    //read data:
    if (openVerification)
    {
        printData (fin);
    }
    else
    {
        cout << "file was not opened correctly" << endl;
    }
    //here the print function gets called only if the file was opened correctly.
    //we pass the file (fin) as reference again bc we need changes to happen to original fin too.

    //close file:
    closeFile (fin);
    //simply closes file via fin.
    return 0;
}


/*
///////////////
///////////////
BELOW IS THE SAME PROGRAM WITHOUT USAGE OF FUNCTIONS
///////////////
///////////////
*/


/*
int main() {
    ifstream fin;
    fin.open("hankTutorial.txt");
    if (fin.is_open())
    {
        int x;
        while (fin >> x)
        {
            cout << x << endl;
        }

        fin.close();
    }
    else
    {
        cout << "the file was not successfully opened!" << endl;
    }
    return 0;
}
*/
