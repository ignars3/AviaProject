#include "../AviaProject/FacadeComputer.h"
#include <conio.h>
#include <tuple>

void printFirst(FacadeComputer computer)
{
	cout << " 1) To see all available tickets" << endl;
	cout << " 2) To see all available planes" << endl;
	cout << " 3) To see your tickets" << endl;
	cout << " 4) To buy ticket" << endl;
	cout << " 5) To delay ticket" << endl;
	cout << " 6) Exit and save" << endl;

	int command;

	cout << "Input number of command --> ";
	cin >> command;

	switch (command)
	{
	case 1:
		computer.printAllTickets();
		break;
	case 2:
		computer.printAllPlanes();
		break;
	case 3:
		printSecond(computer);
		break;
	case 4:
		printThird(computer);
		break;
	case 5:
		printFourth(computer);
		break;
	case 6:
		return;
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

void printSecond(FacadeComputer computer)
{
	tuple<string, string, int, string> output = printClientInput();

	cout << "Your tickets:" << endl;

	computer.printClientTickets(get<3>(output));

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printThird(FacadeComputer computer)
{
	tuple<string, string, int, string> output = printClientInput();

	if (get<2>(output) < 18)
	{
		cout << "You must be 18 or older to buy a ticket" << endl;
	}
	else
	{
		computer.printAllTickets();
		cout << "Input trip name and date --> ";

		string name, date;

		cin >> name >> date;
		
		computer.buyTicket(get<3>(output), name, date);

		cout << "You have successfully bought a ticket" << endl;
	}

	int command;

	cout << endl << "Input any key to continue..." << endl;
	cin >> command;

	printFirst(computer);
}

void printFourth(FacadeComputer computer)
{
	tuple<string, string, int, string> output = printClientInput();

	computer.printClientTickets(get<3>(output));

	cout << "Input name and date of ticket that you want to delete --> ";

	string name, date;

	cin >> name >> date;

	bool isDelayed = computer.delayTicket(get<3>(output), name, date);

	if (isDelayed)
	{
		cout << "You have successfully delayed a ticket" << endl;
	}
	else
	{
		cout << "You have inputed wrong ticket" << endl;
	}

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