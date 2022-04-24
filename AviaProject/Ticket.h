#pragma once
#include "Passenger.h"
#include "Plane.h"

class Ticket
{
private:
	string tripName;
	string date;
	Passenger passenger;
	Plane plane;
public:

	Ticket();

	Ticket(string tripName, string date, Plane plane, Passenger passenger);

	Ticket(const Ticket& other);

	bool validate();

	string getTripName()const;

	string getDate()const;

	Passenger getPassenger()const;

	Plane getPlane()const;

	string fileOutput();

	virtual void input(istream& in);

	virtual void output(ostream& out)const;

	void operator+=(Passenger passenger);

	void operator-=(Passenger passenger);

	bool operator==(Ticket& plane);

	bool operator<(Ticket& a);

	bool operator>(Ticket& a);

	istream& operator>>(istream& in);

	ostream& operator<<(ostream& out)const;

	~Ticket();
};