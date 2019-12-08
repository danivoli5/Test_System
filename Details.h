#pragma once
#include"course.h"
#include<string>
#include<vector>
#include<iostream>
#include<Windows.h>
using namespace std;

class Details
{
protected:
	string name,semester, lecturer, subjects, due;
	int year, difficulty;
	vector <Details> all;
public:
	Details();
	Details(string name2, string semester2, string lecturer2, string subjects2, int year2, int difficulty2, string due);
	void addDetails(Details& prof);
	void addDetails(string name2, string semester2, string lecturer2, string subjects2, int year2, int difficulty2, string due);
	int getYear();
	int getDifficulty();
	string getSemester();
	string getLecturer();
	string getSubjects();
	void openInfo(string name, string semester, string lecturer, string subjects, int year, int difficulty, string due);
	~Details();
};

