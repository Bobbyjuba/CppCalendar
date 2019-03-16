/*==========================================================================
=   Programmer:  Brian Roden	               Date: 3/07/2019             =
=                                                                          =
=   Email: bjrygq@mail.umkc.edu                Class: For Fun              =
=                                                                          =
=   Project Title:	C++ Calendar	           Section:                    =
=                                                                          =
=   Current Date: 3/16/2019                    Completed Date:             =
=                                                                          =
=   Version: 1.0   						       Build:                      =
===========================================================================*/
#include <iostream>
#include "Event.h"

void main() {
	int menuOption, testFormat, devCode = 7;
	Event testEvent;

	std::cout << "1. View My Events" << std::endl;
	std::cout << "2. Add An Event" << std::endl;
	std::cout << "3. Remove an Event" << std::endl << std::endl;
	
	// To test dateParser, enter 7 (the developer code)
	std::cout << "What would you like to do? ";
	std::cin >> menuOption;

	// Refer to: SOURCE 1A
	if (menuOption == devCode)
		testFormat = testEvent.dateParser();

	std::cout << testFormat;

	// I already know Sam is going to give me grief over system
	system("pause");
}