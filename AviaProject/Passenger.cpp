#include "Passenger.h"

Passenger::Passenger()
{
	name = "Unknown";
	surname = "Unknown";
	passport = "ERROR404";
	age = 18;
}

Passenger::Passenger(string name, string surname, string passport, int age)
{
	this->name = name;
	this->surname = surname;
	this->passport = passport;
	this->age = age;
}

Passenger::Passenger(const Passenger& other)
{
	name = other.name;
	surname = other.surname;
	passport = other.passport;
	age = other.age;
}

bool Passenger::validate()
{
	return true;
}

string Passenger::getName()const
{
	return name;
}

string Passenger::getSurname()const
{
	return surname;
}

string Passenger::getPassport()const
{
	return passport;
}

int Passenger::getAge()const
{
	return age;
}

string Passenger::fileOutput()
{
	string out = "";

	out += name + " " + surname + " " + passport + " " + to_string(age);
	return out;
}

void Passenger::input(istream& in)
{
	in >> name >> surname >> passport >> age;
}

void Passenger::output(ostream& out)const
{
	out << " Passenger: " << name << " " << surname << ", " << age << " years" << endl;
}

bool Passenger::operator==(Passenger& passenger)
{
	return passport == passenger.passport;
}

bool Passenger::operator<(Passenger& a)
{
	if (name < a.name)
	{
		return true;
	}

	return false;
}

bool Passenger::operator>(Passenger& a)
{
	return !(this->operator<(a));
}

Passenger::~Passenger() {}