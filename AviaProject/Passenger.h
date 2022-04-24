#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger
{
private:
	string name;
	string surname;
	string passport;
	int age;
public:

	Passenger();

	Passenger(string name, string surname, string passport, int age);

	Passenger(const Passenger& other);

	bool validate();

	string getName()const;

	string getSurname()const;

	string getPassport()const;

	int getAge()const;

	string fileOutput();

	virtual void input(istream& in);

	virtual void output(ostream& out)const;

	bool operator==(Passenger& passenger);

	bool operator<(Passenger& a);

	bool operator>(Passenger& a);

	~Passenger();
};