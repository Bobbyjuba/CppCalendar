/*==========================================================================
=   Programmer:  Brian Roden	               Date: 3/07/2019             =
=                                                                          =
=   Email: bjrygq@mail.umkc.edu                Class: For Fun              =
=                                                                          =
=   Project Title:	C++ Calendar	           Section:                    =
=                                                                          =
=   Current Date: 3/29/2019                    Completed Date:             =
=                                                                          =
=   Version: 1.1.2   						   Build:                      =
===========================================================================*/
#include "Event.h"
#include "IO.h"

void main() {
	std::string name = "name", description = "description", menuOption, devCode = "7";
	int formattedDate;


	std::cout << "1. View My Events" << std::endl;
	std::cout << "2. Add An Event" << std::endl;
	std::cout << "3. Remove an Event" << std::endl << std::endl;
	
	// To test, enter 7 (the developer code)
	std::cout << "What would you like to do? ";
	std::getline(std::cin, menuOption);

	if (menuOption == devCode) {
		std::system("CLS");
		formattedDate = IO::formattedDate();
	}

	std::cout << formattedDate << std::endl;

	// I already know Sam is going to give me grief over system
	system("pause");
}