#include "stdafx.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;


Person::Person(string name,int age, int mobilePhoneNumber):name(name),age(age),mobilePhoneNumber(mobilePhoneNumber)
{
	cout << "Person was created" << endl;
}
Person::~Person()
{
	cout << "Person was destroyed" << endl;
}

int Person::getAge()
{
	return this->age;
}

string Person::getName()
{
	return this->name;
}
