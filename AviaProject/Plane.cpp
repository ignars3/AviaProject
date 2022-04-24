#include "Plane.h"

Plane::Plane()
{
	name = "Unknown";
}

Plane::Plane(string name, vector<Passenger> passengers, vector<Pilot> pilots)
{
	this->name = name;
	this->passengers = passengers;
	this->pilots = pilots;
}

Plane::Plane(const Plane& other)
{
	name = other.name;
	passengers = other.passengers;
	pilots = other.pilots;
}

bool Plane::validate()
{
	return true;
}

string Plane::getName()const
{
	return name;
}

vector<Passenger> Plane::getPassengers()const
{
	return passengers;
}

vector<Pilot> Plane::getPilots()const
{
	return pilots;
}

string Plane::fileOutput()
{
	int count = passengers.size();
	string out = "";

	out += name + " ";
	out += count + " ";

	for (int i = 0; i < count; i++)
	{
		out += passengers[i].fileOutput() + " ";
	}

	count = pilots.size();
	out += count + " ";
	for (int i = 0; i < count; i++)
	{
		out += pilots[i].fileOutput() + " ";
	}

	return out;
}

void Plane::input(istream& in)
{
	int count;
	in >> name;

	in >> count;
	for (int i = 0; i < count; i++)
	{
		passengers.push_back(Passenger());
		passengers[i].input(in);
	}

	in >> count;
	for (int i = 0; i < count; i++)
	{
		pilots.push_back(Pilot());
		pilots[i].input(in);
	}
}

void Plane::output(ostream& out)const
{
	out << " Plane: " << name << endl;

	out << "\t Passengers: ";
	for (int i = 0; i < passengers.size(); i++)
	{
		out << passengers[i].getName();
	}
	out << endl;

	out << "\t Pilots: ";
	for (int i = 0; i < pilots.size(); i++)
	{
		out << pilots[i].getName();
	}
	out << endl;
}

void Plane::operator+=(Passenger passenger)
{
	passengers.push_back(passenger);
}

void Plane::operator-=(Passenger passenger)
{
	for (int i = 0; i < passengers.size(); i++)
	{
		if (passenger == passengers[i])
		{
			passengers.erase(passengers.begin() + i);
		}
	}
}

void Plane::operator+=(Pilot pilot)
{
	pilots.push_back(pilot);
}

void Plane::operator-=(Pilot pilot)
{
	for (int i = 0; i < pilots.size(); i++)
	{
		if (pilot == pilots[i])
		{
			pilots.erase(pilots.begin() + i);
		}
	}
}

bool Plane::operator==(Plane& plane)
{
	return name == plane.name;
}

bool Plane::operator<(Plane& a)
{
	if (name < a.name)
	{
		return true;
	}

	return false;
}

bool Plane::operator>(Plane& a)
{
	return !(this->operator<(a));
}

Plane::~Plane() {}