/*==========================================================================
=   Programmer:  Brian Roden	               Date: 3/07/2019             =
=                                                                          =
=   Email: bjrygq@mail.umkc.edu                Class: For Fun              =
=                                                                          =
=   Project Title:	C++ Calendar	           Section:                    =
=                                                                          =
=   Current Date: 3/31/2019                    Completed Date:             =
=                                                                          =
=   Version: 1.2.1   						   Build:                      =
===========================================================================*/
#include "Event.h"
#include "IO.h"

void showMenu();

void main() {
	std::string name = "name", description = "description", devCode = "7";
	int formattedDate, menuOption;

	showMenu();

	// To test, enter 7 (the developer code)
	std::cin >> menuOption;
	std::cin.ignore();

	switch (menuOption) {
	case 1:
		std::cout << std::endl << "This feature has not been added... yet." << std::endl;
		break;

	case 2:
		std::cout << std::endl << "This feature has not been added... yet." << std::endl;
		break;

	case 3:
		std::cout << std::endl << "This feature has not been added... yet." << std::endl;
		break;

	case 4:
		exit(1);
		break;

	case 7:
		IO::clearScreen();
		name = IO::stringInitial(name);
		description = IO::stringInitial(description);
		formattedDate = IO::formattedDate();
		break;

	default:
		IO::clearScreen();
		showMenu();
	}
}

void showMenu() {
	std::cout << "1. View My Events" << std::endl;
	std::cout << "2. Add An Event" << std::endl;
	std::cout << "3. Remove an Event" << std::endl;
	std::cout << "4. Exit" << std::endl << std::endl;

	std::cout << "What would you like to do? ";
}