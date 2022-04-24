#pragma once
#include "Passenger.h"
#include "Ticket.h"
#include "Pilot.h"
#include "Plane.h"
#include <fstream>

class FacadeComputer
{
private:
	vector<Passenger> passengers;
	vector<Ticket> tickets;
	vector<Pilot> pilots;
	vector<Plane> planes;
public:

	FacadeComputer();

	void saveData();
	void loadData();

	void createPassenger(string name, string surname, string passport, int age);
	void createPilot(string name, string surname, int experience);
	void createTicket(string tripName, string date, Plane plane);
	void createPlane(string name);

	void buyTicket(string passport, string tripName, string planeName);
	void delayTicket(string passport, string tripName, string planeName);

	void changePilot(string name, string surname, string planeName);

	void printClientTickets(string passport);

	void printAllPlanes();
	void printAllPilots();
	void printAllTickets();
	void printAllPassengers();

	~FacadeComputer();
};