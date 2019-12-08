#pragma once
#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Teacher
{
protected:
	long phone;
	int password;
	string name, sub;
	vector <Teacher> professors;
public:
	long getPhone(); 
	long getPass();
	string getName();
	string getSub();
	Teacher(Teacher const& prof);
	Teacher(string name2, string subject, long phone2, int pass);
	void addTeacher(Teacher const & prof);
	void addTeacher(string name2, string subject, long phone2, int pass);
};