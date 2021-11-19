#include"Admin.h"
void Admin::add_admin()
{
    adf.open("Admin_Data.txt", ios::app);

    cout << "\n\nEnter the id: ";
    cin >> this->id;

    cin.ignore();
    cout << "\nEnter the name: ";
    cin.getline(this->name, 30);

    cout << "\nSet the password for ur id: ";
    cin.getline(this->pass, 30);

    adf << endl << this->id << "," << this->pass << "-" << this->name << endl;
    adf.close();

    cout << "\n\n\t\t\t\tYou've successfully added an admin!\n\n";
    return;

}
void Admin::append(Student d)
{
    stu.open("student.txt", ios::app);
    marks.open("Marks.txt", ios::app);


    cout << "Enter the id: ";
    cin >> d.id;

    cin.ignore();
    cout << "Enter the name: ";
    cin.getline(d.name, 30);

    cout << "Set the password: ";
    cin.getline(d.pass, 30);

    cout << "Enter the name of program: ";
    cin.getline(d.degree, 10);

    cout << "Enter the batch number: ";
    cin >> d.batch;

    cout << "How many courses: ";
    cin >> d.t_course;


    cin.ignore();
    cout << "Enter the name of courses u want to assign (courses must be seperated by commas): ";
    cin.getline(d.courses, 60);

    marks <<endl<< d.id << "," << d.name << "-" << d.courses<<"!"<< d.t_course << ",";
    stu << endl << d.id << "," << d.pass << "-" << d.name << ","<<d.degree<<","<< d.batch;
    stu.close();

    while (d.t_course>0)
    {
        marks << "$";
        d.t_course--;
    }

    marks.close();


    return;
}

void Admin::display()
{
    cout << endl << endl << "\t\t\t\t\t\t Students's Record" << endl << endl;
    cout << endl << endl << right << setw(4) << "ID \t" << left << setw(30) << "Name" << left << setw(10) << "Degree" << left << setw(10) << "Batch" << left << setw(20) << "Total courses" << left << setw(60) << "Course names" << endl;
    int t = 0;
    while (t<100)
    {
        cout << "_";
        t++;
    }
    cout << endl << endl;

    stu.open("student.txt");
    marks.open("Marks.txt");
    while (!stu.eof())
    {
        stu >> d.id;
        stu.ignore(10, ',');
        stu.ignore(10, '-');
        stu.getline(d.name, 30, ',');
        stu.getline(d.degree, 10, ',');
        stu >> d.batch;
        stu.ignore();

        marks.ignore(100, '-');
        marks.getline(d.courses, 60, '!');
        marks >> d.t_course;
        marks.ignore(10, ',');
        marks.ignore(100, '\n');
        cout << left << setw(4) << d.id << "\t" << left << setw(30) << d.name << left << setw(10) << d.degree<< left << setw(10) << d.batch << left << setw(20) << d.t_course << left << setw(60) << d.courses << endl;
    }
    marks.close();
    stu.close();
}
void Admin::erase_std()
{
    int id;
    cout << "ID of the student which has to deleted: ";

    cin >> id;
    stu.open("student.txt");
    marks.open("Marks.txt");
    temp.open("temp.txt", ios::app);
    temp1.open("temp1.txt", ios::app);
    int a = 1;
    while (!stu.eof())
    {
        stu >> d.id;
        stu.ignore(10, ',');
        stu.getline(d.pass, 30, '-');
        stu.getline(d.name, 30, ',');
        stu.getline(d.degree, 10, ',');
        stu >> d.batch;
        stu.ignore();
        marks.ignore(100, '-');
        marks.getline(d.courses, 50, '!');
        marks >> d.t_course;
        marks.ignore(10, ',');
        marks.ignore(100, '\n');

        int id1=d.id;
        if (id1==id)
        {
            a = 0;
            continue;
        }
        else
        {
            temp << endl << d.id << "," << d.pass << "-" << d.name << "," << d.degree << "," << d.batch;
            temp1 << endl << d.id << "," << d.name << "-" << d.courses << "!" << d.t_course << ",";
            while (d.t_course > 0)
            {
                temp1 << "$";
                d.t_course--;
            }
        }
    }
    temp.close();
    stu.close();
    temp1.close();
    marks.close();

    if (a != 0)
    {
        cout << "\n\n\nNot found\n\n";
        return;
    }
    cout << "\n\n Task done.\n\n " ;

    remove("Marks.txt");
    rename("temp1.txt", "Marks.txt");
    remove("student.txt");
    rename("temp.txt", "student.txt");
}
