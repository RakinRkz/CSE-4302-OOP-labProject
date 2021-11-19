#include "Menu.h"

void dis()
{
    system("COLOR 70");
    cout << endl << endl << "        ";
    for (int c = 0; c<30; c++)					// ----> The main heading line
    {
        cout << "*";
    }
    cout << "  _Welcome to The Course Management System_  ";
    for (int c = 0; c<30; c++)
    {
        cout << "*";
    }
    cout << endl;
    cout << endl;

    cout << "\t\t\t\t Please Select the user type to log in : " << endl << endl;
}
void dis1()
{
    cout << "\t\t______________________________________________________\n\n\t\t\t 1. Admin mode\n\t\t\t 2. Student Log In\n\t\t\t 3. Teacher Log In\n\t\t\t 4. Exit the system \n\t\t______________________________________________________" << endl;
    cout << endl << " Please enter your choice (1-4) :   ";
}
void dis2()
{
    cout << "\t\t______________________________________________________\n\n\t\t\t\t ***Admin Dashboard*** \n\n\t\t\t 1. Add a student\n\t\t\t 2. Remove a student\n\t\t\t 3. Add a teacher\n\t\t\t 4. Remove a teacher\n\t\t\t 5. Add an admin\n\t\t\t 6. Display all Students\n\t\t\t 7. Display all teachers\n\t\t\t 8. To go back to the main menu\n\t\t\t 9. To exit the program \n\t\t______________________________________________________\n";

    cout << endl << " Please enter your choice (1-9) :   ";
}
void dis3()
{
    cout << "\t\t______________________________________________________\n\n\t\t\t\t ***Student Section*** \n\n\t\t\t 1. See the assigned courses \n\t\t\t 2. Result of all assigned courses \n\t\t\t 3. To go back to the main menu\n\t\t\t 4. To exit the program\n\t\t______________________________________________________\n";

    cout << endl << " Please enter your choice (1-4) :   ";
}
void dis4()
{
    cout << "\t\t______________________________________________________\n\n\t\t\t\t ***Teacher Section*** \n\n\t\t\t 1. Enter marks of a student in a course \n\t\t\t 2. See the list of courses \n\t\t\t 3. To go back to the main menu\n\t\t\t 4. To exit the program\n\t\t______________________________________________________\n";

    cout << endl << " Please enter your choice (1-5) :   ";
}

