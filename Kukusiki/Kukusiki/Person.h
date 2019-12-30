#pragma once
#include <string>
using namespace std;
class Person
{
public:
	Person(string name,int age, int mobilePhoneNumber);
	~Person();
	int getAge();
	string getName();

private:
	string name;
	int age, mobilePhoneNumber;

};
