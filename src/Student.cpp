#include "Student.h"
void Student::show()
{

    string co;
    marks.open("CurrentStd.txt");
    marks.ignore(100, '-');
    getline(marks, co, '!');
    marks.close();

    marks.open("Marks.txt");
    while (!marks.eof())
    {
        marks.ignore(100, '-');
        marks.getline(this->courses, 60, '!');

        string str(this->courses);
        if (co == str)
        {
            marks >> this->id;
            marks.ignore(10, ',');

            for (int i = 0; i < this->id; i++)
            {
                marks.getline(this->pass, 30, '$');

                if (this->pass == NULL)
                {
                    x1[i] = "No entry";
                    continue;
                }
                x1[i] = this->pass;
            }
        }
        marks.ignore(50, '\n');
    }
    marks.close();


    marks.open("CurrentStd.txt");

    marks.ignore(100, '!');
    marks >> this->id;
    marks.ignore(10, ',');

    marks.close();
    marks.open("CurrentStd.txt");
    marks.ignore(100, '-');

    int j = this->id;
    int i = 0;
    while (j>0)
    {
        if(j==1){
            getline(marks, x[i], '!');
        }
        else
            getline(marks, x[i], ',');
        i++;
        j--;
    }
    j = 0;

    cout << "\nThe marks of assigned courses is following:-\n ";
    cout << endl << "Subjects\t\t\t\tSessional,Mid,Final marks" << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < this->id; i++)
    {
        cout << endl << ++j << ". " << x[i] << "\t\t\t\t\t" << x1[i];
        cout << endl;
    }
    cout << endl << endl;
    marks.close();

}
void Student::see_assigned1()
{
    int j,j1;
    marks.open("CurrentStd.txt");

    marks.ignore(100, '!');
    marks >> j;
    marks.ignore(10, ',');

    marks.close();
    marks.open("CurrentStd.txt");
    marks.ignore(100, '-');

    j1=j;
    int i = 0;
    while (j>0)
    {
        if(j==1){
             getline(marks, x[i], '!');
        }
        else
            getline(marks, x[i], ',');
        i++;
        j--;
    }
    j = 0;
    cout << "\nThe list of assigned courses is following:-\n ";
    for (int i = 0; i < j1; i++)
        cout <<endl<<++j<<". "<< x[i] << "\n";

    cout << endl << endl;
    marks.close();
}
