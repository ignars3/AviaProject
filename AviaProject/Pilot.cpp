#include "Pilot.h"

Pilot::Pilot()
{
	name = "Unknown";
	surname = "Unknown";
	experience = 0;
}

Pilot::Pilot(string name, string surname, int experience, vector<Plane> planes)
{
	this->name = name;
	this->surname = surname;
	this->experience = experience;
	this->planes = planes;
}

Pilot::Pilot(const Pilot& other)
{
	name = other.name;
	surname = other.surname;
	experience = other.experience;
	planes = other.planes;
}

bool Pilot::validate()
{
	return true;
}

string Pilot::getName()const
{
	return name;
}

string Pilot::getSurname()const
{
	return surname;
}

int Pilot::getExperience()const
{
	return experience;
}

vector<Plane> Pilot::getPlanes()const
{
	return planes;
}

void Pilot::input(istream& in)
{
	int count;

	in >> name >> surname >> experience;
	
	in >> count;
	for (int i = 0; i < count; i++)
	{
		planes.push_back(Plane());
		planes[i].input(in);
	}
}

void Pilot::output(ostream& out)const
{
	out << " Pilot: " << name << " " << surname << ", experience - " << experience << " years" << endl;

	out << "\t Planes: ";
	for (int i = 0; i < planes.size(); i++)
	{
		out << planes[i].getName();
	}
	out << endl;
}

void Pilot::operator+=(Plane plane)
{
	planes.push_back(plane);
}

void Pilot::operator-=(Plane plane)
{
	for (int i = 0; i < planes.size(); i++)
	{
		if (plane == planes[i])
		{
			planes.erase(planes.begin() + i);
		}
	}
}

bool Pilot::operator==(Pilot& pilot)
{
	return (name == pilot.surname && surname == pilot.surname);
}

bool Pilot::operator<(Pilot& a)
{
	if (name < a.name)
	{
		return true;
	}

	return false;
}

bool Pilot::operator>(Pilot& a)
{
	return !(this->operator<(a));
}

Pilot::~Pilot() {}