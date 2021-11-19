#include"Password.h"

bool Password::isLogin()
{
    system("cls");
		Password data[3];                                   // ----> Structure Array for storing the read data from the file
		admin.open("Admin_Data.txt");
        string ad_realpass;
        int ad_realid;
		login = false;
		cout << " Enter the ID of admin: ";				// ----> taking input for credentials
		cin >> ad_realid;
		cin.ignore();
		cout << " Enter the admin password: ";
		getline(cin, ad_realpass);						// ----> Opening the file for reading

        while (!admin.eof())
		{
			admin >> ad_id;
			admin.ignore(10, ',');
			admin.getline(ad_pass, 30, '-');
			admin.getline(ad_name, 30,'\n');

			if (ad_realpass == ad_pass && ad_realid == ad_id)
			{
                cout << "\n\n You are successfully logged in Admin section \n\n";
				system("pause");
				login = true;
			}

		}
		admin.close();
		return login;
}
bool Password::isLoginTry()
{
    cout << endl << " Wrong Ussername or Password  Entered!!!!!\n\n" << endl;
		log = false;
		cout << " Do you want to choose another choice ? (y/n)    ";
		cin >> try_top;					// ----> string input for decision
		if (try_top == "y" || try_top == "Y")
		{
			system("cls");
			if (isLogin() == 1)
			{
				log = true;
				system("pause");
				return log;
			}
			else
			{
				isLoginTry();
			}

		}
		else if (try_top == "n" || try_top == "N")
		{
			system("pause");
			exit(0);
		}
		else
		{
			cout << endl << endl << " Wrong choice entered!! The system is exiting due to the wrong format used in admin login. " << endl << endl;
			system("pause");
			exit(0);
		}
		return log;
}
bool Password::isLogin1()
{
    //int i = 0;
		system("cls");
		stu.open("student.txt");						// ----> Opening the file for reading
		marks.open("Marks.txt");
		mar.open("CurrentStd.txt");
		int realid,batch,cour;
		char realpass[30];
		char name[30],name1[10], name2[50];
		login = false;
		int idm;
		cout << " Enter id : ";				// ----> taking input for credentials
		cin >> idm;
		cin.ignore();
		cout << " Enter password: ";
		getline(cin, t_pw);

		while (!stu.eof())
		{
			stu >> realid;
			stu.ignore(10, ',');
			stu.getline(realpass, 30, '-');
			stu.getline(name, 30, ',');
			stu.getline(name1, 10, ',');
			stu >> batch;
			stu.ignore();

			marks.ignore(100, '-');
			marks.getline(name2, 60, '!');
			marks >> cour;
			marks.ignore(10, ',');
			marks.ignore(10, '\n');

			if (realpass == t_pw && idm == realid)
			{
				mar << realid << "," << name << "-"  << name2 << "!" << cour<<",";
				while (cour > 0)
				{
					mar << "$";
					cour--;
				}
				cout << "\n\n You are successfully logged in Student section \n\n";
				system("pause");
				login = true;
			}

		}
		marks.close();
		mar.close();
		stu.close();
		return login;
}
bool Password::isLoginTry1()
{
    cout << endl << " Wrong Ussername or Password  Entered!!!!!\n\n" << endl;
		log = false;
		cout << " Do you want to choose another choice ? (y/n)    ";
		cin >> try_top;					// ----> string input for decision
		if (try_top == "y" || try_top == "Y")
		{
			system("cls");
			if (isLogin1() == 1)
			{
				log = true;
				system("pause");
				return log;
			}
			else
			{
				isLoginTry1();
			}

		}
		else if (try_top == "n" || try_top == "N")
		{
			system("pause");
			exit(0);
		}
		else
		{
			cout << endl << endl << " Wrong choice entered!! The system is exiting due to the wrong format used. " << endl << endl;
			system("pause");
			exit(0);
		}
		return log;
}
bool Password::isLogin2()
{
    //int i = 0;
		system("cls");
		stu.open("teacher.txt");						// ----> Opening the file for reading
		mar.open("teacher_open.txt");
		int realid, id2;
		char realpass[30];
		char name[30], name2[50];
		login = false;
		int idm;
		cout << " Enter id : ";				// ----> taking input for credentials
		cin >> idm;
		cin.ignore();
		cout << " Enter password: ";
		getline(cin, t_pw);

		while (!stu.eof())
		{
			stu >> realid;
			stu.ignore(10, ',');
			stu.getline(realpass, 30, '-');
			stu.getline(name, 30, '$');
			stu >> id2;
			stu.ignore(10, '.');
			stu.getline(name2, 50, '\n');

			if (realpass == t_pw && idm == realid)
			{
				mar  << realid << "," << realpass << "-" << name << "$" << id2 << "." << name2;

				cout << "\n\n You are successfully logged in Teacher section \n\n";
				system("pause");
				login = true;
			}

		}
		mar.close();
		stu.close();
		return login;
}
bool Password::isLoginTry2()
{
    cout << endl << " Wrong Ussername or Password  Entered!!!!!\n\n" << endl;
		log = false;
		cout << " Do you want to choose another choice ? (y/n)    ";
		cin >> try_top;					// ----> string input for decision
		if (try_top == "y" || try_top == "Y")
		{
			system("cls");
			if (isLogin2() == 1)
			{
				log = true;
				system("pause");
				return log;
			}
			else
			{
				isLoginTry2();
			}

		}
		else if (try_top == "n" || try_top == "N")
		{
			system("pause");
			exit(0);
		}
		else
		{
			cout << endl << endl << " Wrong choice entered!! The system is exiting due to the wrong format used. " << endl << endl;
			system("pause");
			exit(0);
		}
		return log;
}
