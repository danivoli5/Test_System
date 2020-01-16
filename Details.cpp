#pragma once
#include<direct.h>
#include "Details.h"
#include <string>
#include <iostream>
#include<fstream>
#include<Windows.h>
using namespace std;


int Details::getYear()
{
	return this->year;
}

int Details::getDifficulty()
{
	return this->difficulty;
}


string Details::getSemester()
{
	return this->semester;
}

string Details::getLecturer()
{
	return this->lecturer;
}

string Details::getSubjects()
{
	return this->subjects;
}

void Details::openInfo(string name, string semester, string lecturer, string subjects, int year, int difficulty, string due)
{
	string temp = name + ' ' + to_string(year) + ' ' + semester + ' ' + due + ' ' + lecturer + ' ' + subjects + ' ' + to_string(difficulty) + ' ' + ".docx";	
	system(temp.c_str());
	system("pause");
}


Details::~Details()
{
}

Details::Details()
{
}

Details::Details(string name2, string semester2, string lecturer2, string subjects2, int year2, int difficulty2, string due2)
	: name(name2), semester(semester2), lecturer(lecturer2), subjects(subjects2), year(year2), difficulty(difficulty2), due(due2)
{
	string data;
	string temp = name2 + ' ' + to_string(year2) + ' ' + semester2 + ' ' + due2 + ' ' + lecturer2 + ' ' + subjects2 + ' ' + to_string(difficulty2) + ".docx";
	ofstream file1;
	file1.open(temp);
	file1.close();
}

void Details::addDetails(Details& temp)
{
	all.push_back(temp);
	this->difficulty = temp.difficulty;
	this->due = temp.due;
	this->lecturer = temp.lecturer;
	this->name = temp.name;
	this->semester = temp.semester;
	this->subjects = temp.subjects;
	this->year = temp.year;
}

void Details::addDetails(string name2, string semester2, string lecturer2, string subjects2, int year2, int difficulty2, string due)
{
	Details temp(name2, semester2, lecturer2, subjects2, year2, difficulty2, due);
	all.push_back(temp);
}
