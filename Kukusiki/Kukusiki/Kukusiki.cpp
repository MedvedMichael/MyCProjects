// Kukusiki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>;
#include "Person.h";
using namespace std;

int main()
{
	Person *person = new Person("Michael",2,5);
	cout << person->getAge() << endl;
	cout << person->getName() << endl;
	delete person;
}


