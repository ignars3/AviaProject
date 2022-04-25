#include "../AviaProject/FacadeComputer.h"
#include <conio.h>
#include <tuple>

void printFirst(FacadeComputer computer)
{
	cout << " 1) To create new passenger" << endl;
	cout << " 2) To create new pilot" << endl;
	cout << " 3) To create new ticket" << endl;
	cout << " 4) To create new plane" << endl;

	cout << " 5) To set pilot to the plane" << endl;
	cout << " 6) To unset pilot from the plane" << endl;

	cout << " 7) To print all tickets" << endl;
	cout << " 8) To print all planes" << endl;
	cout << " 9) To print all pilots" << endl;
	cout << " 10) To print all passengers" << endl;

	cout << " 11) Exit and save" << endl;

	int command;

	cout << "Input number of command --> ";
	cin >> command;

	switch (command)
	{
	case 1:
		printSecond(computer);
		break;
	case 2:
		printThird(computer);
		break;
	case 3:
		printFourth(computer);
		break;
	case 4:
		printFifth(computer);
		break;
	case 5:
		printSixth(computer);
		break;
	case 6:
		printSeventh(computer);
		return;
	case 7:
		computer.printAllTickets();
		break;
	case 8:
		computer.printAllPlanes();
		break;
	case 9:
		computer.printAllPilots();
		break;
	case 10:
		computer.printAllPassengers();
		break;
	case 11:
		return;
		break;
	default:
		system("cls");

		cout << "/t Wrong input. Try again" << endl << endl;
		printFirst(computer);
		break;
	}

	system("cls");
	printFirst(computer);
}

tuple<string, string, int, string> printClientInput()
{
	string name, surname, passport;
	int age;

	cout << "Input your name --> ";
	cin >> name;

	cout << "Input your surname --> ";
	cin >> surname;

	cout << "Input your age --> ";
	cin >> age;

	cout << "Input your passport --> ";
	cin >> passport;

	system("cls");
	return make_tuple(name, surname, age, passport);

}
tuple<string, string, int> printPilotInput()
{
	string name, surname;
	int experience;

	cout << "Input name of pilot --> ";
	cin >> name;

	cout << "Input surname of pilot --> ";
	cin >> surname;

	cout << "Input experience of pilot --> ";
	cin >> experience;

	system("cls");
	return make_tuple(name, surname, experience);
}

tuple<string, string, string> printTicketInput()
{
	string tripName, date, planeName;

	cout << "Input name of the ticket --> ";
	cin >> tripName;

	cout << "Input date of the ticket --> ";
	cin >> date;

	cout << "Input plane`s name of the ticket --> ";
	cin >> planeName;

	system("cls");
	return make_tuple(tripName, date, planeName);
}

string printPlaneInput()
{
	string name;

	cout << "Input name of the plane --> ";
	cin >> name;


	system("cls");
	return name;
}

void printSecond(FacadeComputer computer)
{
	tuple<string, string, int, string> output = printClientInput();

	computer.createPassenger(get<0>(output), get<1>(output), get<3>(output), get<2>(output));

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printThird(FacadeComputer computer)
{
	tuple<string, string, int> output = printPilotInput();

	computer.createPilot(get<0>(output), get<1>(output), get<2>(output));

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printFourth(FacadeComputer computer)
{
	tuple<string, string, string> output = printTicketInput();

	bool isCreated = computer.createTicket(get<0>(output), get<1>(output), get<2>(output));

	if (isCreated)
	{
		cout << "You have successfully created a ticket" << endl;
	}
	else
	{
		cout << "You have inputed wrong plane" << endl;
	}

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printFifth(FacadeComputer computer)
{
	string output = printPlaneInput();

	computer.createPlane(output);

	cout << "You have successfully created a plane" << endl;

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printSixth(FacadeComputer computer)
{
	string output = printPlaneInput();
	tuple<string, string, int> outputPilot = printPilotInput();

	computer.changePilot(get<0>(outputPilot), get<1>(outputPilot), output);

	cout << "You have successfully added a pilot to the plane" << endl;

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printSeventh(FacadeComputer computer)
{
	string output = printPlaneInput();
	tuple<string, string, int> outputPilot = printPilotInput();

	computer.changePilot(get<0>(outputPilot), get<1>(outputPilot), output);

	cout << "You have successfully removed a pilot from the plane" << endl;

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

int main()
{
	cout << "\t Welcome!" << endl << endl;

	FacadeComputer computer = FacadeComputer();
	computer.loadData();

	printFirst(computer);

	computer.saveData();

	_getch();
	return 0;
}