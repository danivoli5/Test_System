#include "Teacher.h"

long Teacher::getPhone()
{
	return this->phone;
}

long Teacher::getPass()
{
	return this->password;
}

string Teacher::getName()
{
	return this->name;
}

string Teacher::getSub()
{
	return this->sub;
}

Teacher::Teacher(Teacher const& prof)
{
	password = prof.password;
	phone = prof.phone;
	sub = prof.sub;
	name = prof.name;
	professors.push_back(prof);
}

Teacher::Teacher(string name2, string subject, long phone2, int pass)
	:name(name2), sub(subject), phone(phone2), password(pass)
{
}

void Teacher::addTeacher(Teacher const& prof)
{
	this->password = prof.password;
	this->phone = prof.phone;
	this->sub = prof.sub;
	this->name = prof.name;
}

void Teacher::addTeacher(string name2, string subject, long phone2, int pass)
{
	Teacher prof(name2, subject, phone2, pass);
	this->professors.push_back(prof);
	this->password = pass;
	this->phone = phone2;
	this->sub = subject;
	this->name = name2;
}
