/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#include <iostream>
#include "Executive.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Incorrect number of parameters!\n";
        return 1;
    }
    //else
    {
        
        Executive *exec = new Executive(); //sample creation of executive object
        try
        {
            exec->maketree(argv[1]);
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
            return 1;
        }
        exec->printMenu();
        delete exec;
        exec = nullptr;
    }

    return 0;
}
