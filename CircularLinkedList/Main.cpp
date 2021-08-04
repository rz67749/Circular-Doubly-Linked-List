#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CircularLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char** argv)
{
    // read in the input file
    CircularLinkedList list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);
    
    if(fs.is_open())
    {
        fs >> input;
        while(!fs.eof())
        {
      
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }//while
    }//if
    else {
        cout << "Failed to open the input file" << endl;
        return 0;
    }//else

    // user options
    cout << "insert (i), delete (d), length (l), print (p), quit (q)" << "\n" << endl;

    char userInput = ' ';
    while(userInput != 'q')
    {
        //user choice 
        cout << "Enter a command: ";
        cin >> userInput;
        cout << endl;
    
        switch(userInput)
        {
        case 'i': // insert
            cout << "Number to insert: ";
            cin >> input;
            cout << endl;
            item.initialize(input);
            list.insertItem(item);
            list.print();
            break;
        case 'd': // delete
            cout << "Number to delete: ";
            cin >> input;
            cout << endl;
            item.initialize(input);
            list.deleteItem(item);
            list.print();
            break;
        case 'l': //length
            cout << "Length: " << list.lengthIs() << "\n" << endl;
            break;
        case 'p': //print list
            list.print();
            break;
        case 'q': //exit program
            cout << "Quitting program..." << endl;
            cout << endl;
            exit(EXIT_SUCCESS);
            break;
        default: // other input 
            cout << "Command not recognized. Try again." << endl;

        }//switch    
        cout << endl;
    }//while
  
    return 0;
  
}//main
