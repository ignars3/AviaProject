#include "Ticket.h"

Ticket::Ticket()
{
	tripName = "Unknown";
	date = "02.08.2002 17:00";
	passenger = Passenger();
	plane = Plane();
}

Ticket::Ticket(string tripName, string date, Plane plane, Passenger passenger = Passenger())
{
	this->tripName = tripName;
	this->date = date;
	this->passenger = passenger;
	this->plane = plane;
}

Ticket::Ticket(const Ticket& other)
{
	tripName = other.tripName;
	date = other.date;
	passenger = other.passenger;
	plane = other.plane;
}

bool Ticket::validate()
{
	return true;
}

string Ticket::getTripName()const
{
	return tripName;
}

string Ticket::getDate()const
{
	return date;
}

Passenger Ticket::getPassenger()const
{
	return passenger;
}

Plane Ticket::getPlane()const
{
	return plane;
}

string Ticket::fileOutput()
{
	string out = "";
	out += tripName + " " + date + " ";
	out += passenger.fileOutput() + " ";
	out += plane.fileOutput();

	return out;
}

void Ticket::input(istream& in)
{
	in >> tripName >> date;
	passenger.input(in);
	plane.input(in);
}

void Ticket::output(ostream& out)const
{
	out << " Ticket: " << tripName << " for " << passenger.getName() << " in " << date << "on plane " << plane.getName() << endl;
}

void Ticket::operator+=(Passenger passenger)
{
	this->passenger = passenger;
}

void Ticket::operator-=(Passenger passenger)
{
	this->passenger = Passenger();
}


bool Ticket::operator==(Ticket& ticket)
{
	return (tripName == ticket.tripName && date == ticket.date && passenger == ticket.passenger && plane == ticket.plane);
}

bool Ticket::operator<(Ticket& a)
{
	
	return false;
}

bool Ticket::operator>(Ticket& a)
{
	return !(this->operator<(a));
}

Ticket::~Ticket() {}