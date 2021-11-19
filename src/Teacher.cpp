#include "Teacher.h"
void Teacher_functionality::append(Teacher t)
{
    tea.open("teacher.txt", ios::app);

    cout << "Enter the id: ";
    cin >> t.id;

    cin.ignore();
    cout << "Enter the name: ";
    cin.getline(t.name, 30);

    cout << "Set the password for ur id: ";
    cin.getline(t.pass, 30);

    cout << "How many courses: ";
    cin >> t.t_course;

    cin.ignore();
    cout << "Enter the name of courses u want to assign (courses must be seperated by commas): ";
    cin.getline(t.courses, 60);

    tea << endl << t.id << "," << t.pass << "-" << t.name << "$" << t.t_course << "." << t.courses;
    tea.close();
    return;


}
void Teacher_functionality::display()
{
    cout << endl << endl << "\t\t\t\t\t\t Teacher's Record" << endl << endl;
    cout << endl << endl << right << setw(4) << "ID \t" << left << setw(30) << "Name" << left << setw(20) << "Total courses" << left << setw(60) << "Course names" << endl;
    int f = 0;
    while (f<100)
    {
        cout << "_";
        f++;
    }
    cout << endl << endl;

    tea.open("teacher.txt");
    while (!tea.eof())
    {
        tea >> t.id;
        tea.ignore(10, ',');
        tea.ignore(10, '-');
        tea.getline(t.name, 30, '$');
        tea >> t.t_course;
        tea.ignore(10, '.');
        tea.getline(t.courses, 50, '\n');

        cout << left << setw(4) << t.id << "\t" << left << setw(30) << t.name  << left << setw(20) << t.t_course << left << setw(60) << t.courses << endl;
        cout << endl;
    }
    tea.close();
    cout << endl << endl;

}
void Teacher_functionality::erasee()
{
    int id;
    cout << "ID of the teacher which has to deleted: ";

    cin >> id;



    tea.open("teacher.txt");
    temp.open("temp.txt", ios::app);

    int a = 1;

    while (!tea.eof())
    {
        tea >> t.id;
        tea.ignore(10, ',');
        tea.getline(t.pass, 30, '-');
        tea.getline(t.name, 30, '$');
        tea >> t.t_course;
        tea.ignore(10, '.');
        tea.getline(t.courses, 50, '\n');
        int i=t.id;
        if (i==id)
        {

            a = 0;
            continue;

        }
        else
        {
            temp << endl << t.id << "," << t.pass << "-" << t.name << "$" << t.t_course << "." << t.courses;
        }
    }



    temp.close();
    tea.close();
    if (a != 0)
    {
        cout << "\n\n\nNot found\n\n";
        return;
    }
    cout << "\n\n Task done.\n\n ";
    remove("teacher.txt");
    rename("temp.txt", "teacher.txt");
}
void Teacher_functionality::see_assigned1()
{
    tea.open("teacher_open.txt");

    tea.ignore(100, '$');
    tea >> t.id;
    tea.ignore(10, '.');

    int j = t.id;
    int i = 0;
    while (j>0)
    {
        getline(tea, x[i], ',');
        i++;
        j--;
    }
    j = 0;
    cout << "\nThe list of assigned courses is following:-\n ";
    for (int i = 0; i < t.id; i++)
        cout << endl << ++j << ". " << x[i] << "\n";

    cout << endl << endl;
    tea.close();
}
void Teacher_functionality::enter_m()
{
    marks.open("Marks.txt");
    cout << "Enter the id of student you want to enter marks: ";
    string e,f;
    int std_id;
    cin >> std_id;
    int p,tid,i,j,a=0;
    while (!marks.eof())
    {
        marks >> t.id;
        marks.ignore(10, ',');
        marks.getline(t.name, 30, '-');
        string str(t.name);
        int id1=t.id;
        if (id1 == std_id)
        {
            a = 1;
            marks.ignore(50, '!');
            marks >> p;
            marks.ignore(10, ',');
        }
        marks.ignore(100, '\n');
    }
    marks.close();

    if (a != 1)
    {
        cout << "\n\nNot found\n\n";
    }
    else
    {
        j = p;
        marks.open("Marks.txt");
        while (!marks.eof())
        {
            marks >> t.id;
            marks.ignore(10, ',');
            marks.getline(t.name, 30, '-');
            string str(t.name);
            int id2=t.id;
            if (id2 == std_id)
            {
                i = 0;
                while (j > 0)
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
                for (int i = 0; i < p; i++)
                    cout << endl << ++j << ". " << x[i] << "\n";

                cout << endl << endl;
            }
            marks.ignore(100, '\n');

        }
        marks.close();

        cout << "Enter the name of subject u want to enter marks: ";
        cin >> f;

        tea.open("teacher_open.txt");
        tea.ignore(100, '$');
        tea >> t.id;
        tea.ignore(10, '.');

        int j = t.id;
        int i = 0;
        while (j>0)
        {
            getline(tea, x1[i], ',');
            i++;
            j--;
        }
        tea.close();

        for (int k = 0; k < t.id; k++)
        {
            if (f == x1[k])
            {
                a = 0;
                cout << " \n\n Yes you r eligible for entering the marks\n\n";

                int rise = 1,xtra;
                for (int i = 0; i < p; i++)
                {
                    if (f == x[i])
                    {
                        break;
                    }
                    rise++;
                }

                cout << "Enter sessional marks: ";
                cin >> stude.sess;
                cout << "Enter mid marks: ";
                cin >> stude.mid;
                cout << "Enter final marks: ";
                cin >> stude.final_m;

                marks.open("Marks.txt");
                temp.open("temp.txt",ios::app);

                while (!marks.eof())
                {
                    marks >> t.id;
                    marks.ignore(10, ',');
                    marks.getline(t.name, 30, '-');
                    marks.getline(t.courses, 60, '!');
                    marks >> tid;
                    marks.ignore(60, '\n');

                    string str(t.name);
                    if (str == e)
                    {
                        temp << endl << t.id << "," << t.name << "-" << t.courses << "!" << tid << ",";
                        rise--;
                        for (int i = 0; i < rise; i++)
                        {
                            temp << "$";
                        }
                        temp << stude.sess << "," << stude.mid << "," << stude.final_m << ",";
                        xtra = tid - rise;
                        for (int i = 0; i < xtra; i++)
                        {
                            temp << "$";
                        }
                    }
                    else
                    {
                        temp << endl << t.id << "," << t.name << "-" << t.courses << "!" << tid << ",";
                        while (tid>0)
                        {
                            temp << "$";
                            tid--;
                        }
                    }
                }

                marks.close();
                temp.close();
                remove("Marks.txt");
                rename("temp.txt", "Marks.txt");
                cout << " DONE!!!!!!!!!!!!!!!!!!!!1";
            }
        }
        if (a != 0)
        {
            cout << " \n\n You are not eligible for entering the marks\n\n\n";
            return;
        }
    }
}

