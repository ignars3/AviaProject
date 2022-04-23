#pragma once
#include "Passenger.h"
#include "Pilot.h"

class Pilot;

class Plane
{
private:
	string name;
	vector<Passenger> passengers;
	vector<Pilot> pilots;
public:

	Plane();

	Plane(string name, vector<Passenger> passengers, vector<Pilot> pilots);

	Plane(const Plane& other);

	bool validate();

	string getName()const;

	vector<Passenger> getPassengers()const;

	vector<Pilot> getPilots()const;

	virtual void input(istream& in);

	virtual void output(ostream& out)const;

	void operator+=(Passenger passanger);
	void operator-=(Passenger passanger);

	void operator+=(Pilot pilot);
	void operator-=(Pilot pilot);

	bool operator==(Plane& plane);

	bool operator<(Plane& a);

	bool operator>(Plane& a);

	~Plane();
};