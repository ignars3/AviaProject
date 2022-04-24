#include "FacadeComputer.h"

istream& operator>>(istream& in, Ticket& d)
{
	d.input(in);
	return in;
}

ostream& operator<<(ostream& out, const Ticket& d)
{
	d.output(out);
	return out;
}

istream& operator>>(istream& in, Pilot& d)
{
	d.input(in);
	return in;
}

ostream& operator<<(ostream& out, const Pilot& d)
{
	d.output(out);
	return out;
}

istream& operator>>(istream& in, Plane& d)
{
	d.input(in);
	return in;
}

ostream& operator<<(ostream& out, const Plane& d)
{
	d.output(out);
	return out;
}

istream& operator>>(istream& in, Passenger& d)
{
	d.input(in);
	return in;
}

ostream& operator<<(ostream& out, const Passenger& d)
{
	d.output(out);
	return out;
}

FacadeComputer::FacadeComputer()
{
	loadData();
}

void FacadeComputer::saveData()
{
	ofstream fout("Data.txt");
	if (fout.is_open())
	{
		fout << tickets.size() + planes.size() + pilots.size() + passengers.size() << endl;

		for (int i = 0; i < tickets.size(); i++)
		{
			fout << "Ticket " << tickets[i];
		}

		for (int i = 0; i < planes.size(); i++)
		{
			fout << "Planes " << planes[i];
		}

		for (int i = 0; i < pilots.size(); i++)
		{
			fout << "Pilot " << pilots[i];
		}

		for (int i = 0; i < passengers.size(); i++)
		{
			fout << "Passengers" << passengers[i];
		}
	}
}

void FacadeComputer::loadData()
{
	ifstream fin("Data.txt");
	if (fin.is_open())
	{
		int n;
		fin >> n;

		string type;

		for (int i = 0; i < n; i++)
		{
			fin >> type;

			if (type == "Ticket")
			{
				Ticket temp;
				fin >> temp;

				tickets.push_back(temp);
			}
			else if (type == "Plane")
			{
				Plane temp;
				fin >> temp;

				planes.push_back(temp);
			}
			else if (type == "Pilot")
			{
				Pilot temp;
				fin >> temp;

				pilots.push_back(temp);
			}
			else if (type == "Passenger")
			{
				Passenger temp;
				fin >> temp;

				passengers.push_back(temp);
			}
			else
			{
				cout << "An error occured while loading data" << endl;
			}
		}
	}
	else
	{
		cout << "An error occured while oppening the file" << endl;
	}
}

void FacadeComputer::createPassenger(string name, string surname, string passport, int age) 
{
	passengers.push_back(Passenger(name, surname, passport, age));
}

void FacadeComputer::createPilot(string name, string surname, int experience) 
{
	pilots.push_back(Pilot(name, surname, experience, vector<Plane>()));
}

void FacadeComputer::createTicket(string tripName, string date, Plane plane) 
{
	tickets.push_back(Ticket(tripName, date, plane, Passenger()));
}

void FacadeComputer::createPlane(string name) 
{
	planes.push_back(Plane(name, vector<Passenger>(), vector<Pilot>()));
}


void FacadeComputer::buyTicket(string passport, string tripName, string planeName)
{
	for (int i = 0; i < passengers.size(); i++)
	{
		if (passengers[i].getPassport() == passport)
		{
			for (int j = 0; j < tickets.size(); j++)
			{
				if (tickets[j].getTripName() == tripName && tickets[j].getPlane().getName() == planeName)
				{
					tickets[j] += passengers[i];
					tickets[j].getPlane() += passengers[i];
					return;
				}
			}
		}
	}
}

void FacadeComputer::delayTicket(string passport, string tripName, string planeName)
{
	for (int i = 0; i < passengers.size(); i++)
	{
		if (passengers[i].getPassport() == passport)
		{
			for (int j = 0; j < tickets.size(); j++)
			{
				if (tickets[j].getTripName() == tripName && tickets[j].getPlane().getName() == planeName && tickets[j].getPassenger().getPassport() == passport)
				{
					tickets[j] -= passengers[i];
					tickets[j].getPlane() -= passengers[i];
					return;
				}
			}
		}
	}
}

void FacadeComputer::changePilot(string name, string surname, string planeName)
{
	for (int i = 0; i < pilots.size(); i++)
	{
		if (pilots[i].getName() == name && pilots[i].getSurname() == surname)
		{
			for (int j = 0; j < planes.size(); j++)
			{
				if (planes[j].getName() == planeName)
				{
					for (int l = 0; l < planes[j].getPilots().size(); l++)
					{
						if (planes[j].getPilots()[l].getName() == name && planes[j].getPilots()[l].getSurname() == surname)
						{
							planes[j] -= pilots[i];
							pilots[i] -= planes[j];
							return;
						}
					}

					planes[j] += pilots[i];
					pilots[i] += planes[j];
				}
			}
		}
	}
}

void FacadeComputer::printClientTickets(string passport)
{
	for (int i = 0; i < planes.size(); i++)
	{
		if (tickets[i].getPassenger().getPassport() == passport)
		{
			cout << tickets[i];
		}
	}
}

void FacadeComputer::printAllPlanes()
{
	for (int i = 0; i < planes.size(); i++)
	{
		cout << planes[i];
	}
}

void FacadeComputer::printAllPilots()
{
	for (int i = 0; i < pilots.size(); i++)
	{
		cout << pilots[i];
	}
}

void FacadeComputer::printAllTickets()
{
	for (int i = 0; i < tickets.size(); i++)
	{
		cout << tickets[i];
	}
}

void FacadeComputer::printAllPassengers()
{
	for (int i = 0; i < passengers.size(); i++)
	{
		cout << passengers[i];
	}
}

FacadeComputer::~FacadeComputer() {}