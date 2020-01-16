#pragma once
#include <direct.h>
#include <ctime>
using namespace std;
#include <string>
#include <iostream>
#include<fstream>
#include<Windows.h>
#include"Details.h"
#include "Teacher.h"
int Add_q(string name2, string semester2, string lecturer2, string subjects2, int year2, int difficulty2, string due)
{

	cout << "Press enter when you ready to crop, In the end press CTRL+V in the word.doc" << endl;
	getchar();
	keybd_event(VK_LWIN, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(0x53, 0, 0, 0);
	keybd_event(NULL, NULL, NULL, NULL);
	keybd_event(0, 0, 0, 0);
	Details temp(name2, semester2, lecturer2, subjects2, year2, difficulty2, due);
	temp.openInfo(name2, semester2, lecturer2, subjects2, year2, difficulty2, due);
	return 0;
}

void questions(int num)
{
	int words = 0;
	ifstream fin;
	ofstream stuff;
	stuff.open("new_test.txt");
	fin.open("question.txt", ios::in);
	char str[20];
	char my_character, num2;

	while (!fin.eof()) {

		fin.get(my_character);
		cout << my_character;
		if (my_character == ' ') {
			words++;
			if (words == 7) {
				cin.getline(str, 20);
				fin.get(num2);
				if (num == num2) {
					stuff << str;
				}
			}
		}

	}

}

int main()
{
	ofstream log;
	log.open("file_log.txt");//log
	time_t my_time = time(NULL);
	log << "starting runing time in nano seconds: " << my_time << endl;
	int logCounter = 0;
	ofstream coor, student, teach, quest;
	ifstream read;
	quest.open("question.txt", ios_base::app);
	quest.close();
	coor.open("coordinators.txt", ios_base::app);
	coor.close();
	student.open("students.txt", ios_base::app);
	student.close();
	teach.open("teacher.txt", ios_base::app);
	teach.close();

	int person, index, index2, size1, size2;
	Details all;
	Details temp;
	ofstream file2;
	vector <string> coordinators;
	string tempStr;
	string name, semester, str, lecturer, subjects, due, Pname, sub, temp2, tempPass;
	int year, difficulty, num, x, length;
	long phone, pass, password;
	do
	{
		cout << "\nwho are you? enter a number: \n 1.coordinator, 2.proffesor, 3.student,0.exit\n";
		cin >> person;
		switch (person)
		{
		case 1:
			log << "coordinator function runing " << endl;//log file runing
			logCounter++;
			cout << "choose 1 to create a new account or 2 to enter to your account" << endl;
			cin >> index;
			if (index == 1)
			{
				log << "creating coordinator account function runing " << endl;//writing into log file
				logCounter++;
				cout << "enter your name : " << endl;
				cin >> Pname;
				cout << "enter password : " << endl;
				cin >> tempPass;
				coor.open("coordinators.txt", ios::app);
				coor << Pname << endl;
				coor << tempPass << endl;
				coor.close();
				tempStr = Pname + ' ' + tempPass;
				coordinators.push_back(tempStr);
			}
			if (index == 2)
			{
				log << "login function runing " << endl;//writing to log file
				logCounter++;
				cout << "enter your name and password:" << endl;
				cin >> Pname;
				cin >> tempPass;
				int k = 0;
				tempStr = Pname + ' ' + tempPass;
				for (int i = 0; i < coordinators.size(); i++) {
					if (strcmp(coordinators[i].c_str(), tempStr.c_str()) == 0) {
						k++;
					}
				}
				if (k == 0)
				{
					log << "a wrong input was entered." << endl;//log file runing
					logCounter++;
					cout << "wrong name or password. please try again" << endl;
					break;
				}
				do
				{
					cout << "enter a number: 0. exit 1.delete a question 2. add a question 3. open a question 4. enter a new teacher 5. add a new student";
					cin >> num;
					switch (num)
					{
					case 1:
					{
						log << "function to delete a question was used." << endl;//log file runing
						logCounter++;
						cout << "enter the name, semester, lecturer, subjects, due, year , difficulty" << endl;
						cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
						tempStr = name + ' ' + to_string(year) + ' ' + semester + ' ' + due + ' ' + lecturer + ' ' + subjects + ' ' + to_string(difficulty) + ' ' + ".docx";
						if (remove(tempStr.c_str()) != 0)
							perror("Error deleting file");
						else
							puts("File successfully deleted");
						file2.close();
						break;
					}
					case 2:
					{
						log << "function to add a question was used." << endl;//log file runing
						logCounter++;
						cout << "enter the name, semester, lecturer, subjects, due, year difficulty" << endl;
						cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
						tempStr = name + ' ' + to_string(year) + ' ' + semester + ' ' + due + ' ' + lecturer + ' ' + subjects + ' ' + to_string(difficulty) + ' ' + ".docx";
						temp.addDetails(name, semester, lecturer, subjects, year, difficulty, due);
						all.addDetails(temp);
						quest.open("question.txt", ios::app);
						quest << tempStr << endl;
						quest.close();
						//Add_q(name, semester, lecturer, subjects, year, difficulty, due);
						break;
					}
					case 3:
					{
						log << "opening the question file requested." << endl;//log file runing
						logCounter++;
						cout << "enter the name, semester, lecturer, subjects, due, year and difficulty" << endl;
						cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
						all.openInfo(name, semester, lecturer, subjects, year, difficulty, due);
						break;
					}
					case 4:
					{
						log << "adding a new teacher function runing " << endl;//log file writing
						logCounter++;
						cout << "enter the name: ";
						cin >> Pname;
						cout << "\nenter phone number: ";
						cin >> phone;
						cout << "\nenter subject: ";
						cin >> sub;
						cout << "\n enter password: ";
						cin >> pass;
						Teacher teacher(Pname, sub, phone, pass);
						Teacher tempTeach(teacher);
						teach.open("teacher.txt", ios::app);
						teach << Pname << endl;
						teach << pass << endl;
						teach.close();
						break;
					}
					case 5:
					{
						log << "function to add a new student " << endl;//writing to log file
						logCounter++;
						cout << "enter name and password" << endl;
						cin >> Pname >> pass;
						student.open("students.txt", ios::app);
						student << Pname <<endl<< pass<<endl;
						student.close();
						break;

					}

					}
				}while (num != 0);
			}
			break;
        case 2:
			cout << "enter your name and password" << endl;
			cin >> Pname;
			cin >> tempPass;
			read.open("teacher.txt", ios::app);
			tempStr = "";
			while (!read.eof()) {
				while (read >> name && name != "\n")
				{
					tempStr += name;
				}
				if (tempStr == Pname)
				{
					read.eof();
					goto continueTo;
				}
			}
			cout << "no matching password or name, please try again" << endl;
			break;
			continueTo:
			cout << "enter 0 to exit, enter 1 to search a question, enter 2 to add a question" << endl;
			cin >> index2;
			if (index2 == 0)
				break;
			else if (index2 == 1) {
				log << "function to search a question runings." << endl;//log file runing
				logCounter++;
				cout << "enter the name, semester, lecturer, subjects, due, year, difficulty" << endl;
				cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
				all.openInfo(name, semester, lecturer, subjects, year, difficulty, due);
				break;
			}
			else if (index2 == 2) {
				log << "function to add a question runings." << endl;//log file runing
				logCounter++;
				cout << "enter the name, semester, lecturer, subjects, due, year difficulty" << endl;
				cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
				temp.addDetails(name, semester, lecturer, subjects, year, difficulty, due);
				all.addDetails(temp);
				x = Add_q(name, semester, lecturer, subjects, year, difficulty, due);
				break;
			}
			break;
		case 3:
			cout << "enter 0 to exit, enter 1 to search a question" << endl;
			cin >> index2;
			if (index2 == 0)
				break;
			else if (index2 == 1) {
				cout << "enter the name, semester, lecturer, subjects, due, year, difficulty" << endl;
				cin >> name >> semester >> lecturer >> subjects >> due >> year >> difficulty;
				all.openInfo(name, semester, lecturer, subjects, year, difficulty, due);
			}
			break;
		}
	}

	while (person != 0);

	time_t my_time2 = time(NULL);
	log << "ending runing time in nano seconds: " << my_time2 << endl;// print to log file
	log << "total run time: " << my_time2 - my_time << endl;//print to log file
	log << "total log usage: " << logCounter << endl;
	cout << "bye bye";
	log.close();// closing of log file
	return 0;
}



