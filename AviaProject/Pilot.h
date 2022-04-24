#pragma once
#include "Plane.h"

class Plane;

class Pilot
{
private:
	string name;
	string surname;
	int experience;
	vector<Plane> planes;
public:

	Pilot();

	Pilot(string name, string surname, int experience, vector<Plane> planes);

	Pilot(const Pilot& other);

	bool validate();

	string getName()const;

	string getSurname()const;

	int getExperience()const;

	vector<Plane> getPlanes()const;

	string fileOutput();

	virtual void input(istream& in);

	virtual void output(ostream& out)const;

	void operator+=(Plane plane);
	void operator-=(Plane plane);

	bool operator==(Pilot& pilot);

	bool operator<(Pilot& a);

	bool operator>(Pilot& a);

	~Pilot();
};