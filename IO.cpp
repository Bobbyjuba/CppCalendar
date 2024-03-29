#include "IO.h"

void IO::clearScreen() {
	HANDLE						hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO	csbi;
	DWORD						count;
	DWORD						cellCount;
	COORD						homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	// Get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	// Fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	// Fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	// Move the cursor home
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void IO::newLineSpace() {
	std::cout << "-------------------------------------------------" << std::endl;
}

std::string IO::stringInitial(std::string strToWriteTo) {
	// ProceedStr will hold the user's string response, and proceed will control the while-loop
	std::string proceedStr;
	bool proceed = false;

	// Refer to: IO 1A + 1B
	if (strToWriteTo == "name") {
		IO::newLineSpace();
		std::cout << "Please give a name for your event: " << std::endl;
		IO::newLineSpace();

		std::getline(std::cin, strToWriteTo);

		// Let the user keep editing the name until they are satisfied with it
		while (!proceed) {
			IO::newLineSpace();
			std::cout << "Is this name correct \"" << strToWriteTo << "\" ? (Y/N) : " << std::endl;
			IO::newLineSpace();

			std::getline(std::cin, proceedStr);

			// Convert proceedStr to lowercase for checking purposes
			std::transform(proceedStr.begin(), proceedStr.end(), proceedStr.begin(), ::tolower);

			if (proceedStr == "y" || proceedStr == "yes")
				proceed = true;

			else if (proceedStr == "n" || proceedStr == "no") {
				IO::newLineSpace();
				std::cout << "Please give a name for your event: " << std::endl;
				IO::newLineSpace();

				std::getline(std::cin, strToWriteTo);
			}

			else {
				IO::newLineSpace();
				std::cout << "Unexpected input" << std::endl;
			}
		}
	}

	// This section will execute if the user is adding a description to their event
	// More or less, this code is the same as the code for name
	if (strToWriteTo == "description") {
		IO::newLineSpace();
		std::cout << "Please give a description for your event: " << std::endl;
		IO::newLineSpace();

		std::getline(std::cin, strToWriteTo);

		while (!proceed) {
			IO::newLineSpace();
			std::cout << "Is this description correct?" << std::endl << std::endl;
			std::cout << "\"" << strToWriteTo << "\" (Y/N) : " << std::endl;
			IO::newLineSpace();

			std::getline(std::cin, proceedStr);

			std::transform(proceedStr.begin(), proceedStr.end(), proceedStr.begin(), ::tolower);

			if (proceedStr == "y" || proceedStr == "yes")
				proceed = true;

			else if (proceedStr == "n" || proceedStr == "no") {
				IO::newLineSpace();
				std::cout << "Please give a description for your event: " << std::endl;
				IO::newLineSpace();

				std::getline(std::cin, strToWriteTo);
			}

			else {
				IO::newLineSpace();
				std::cout << "Unexpected input" << std::endl;
			}
		}
	}

	// Return whichever variable the user edited, so the correlating variable can be set in the Event object
	return strToWriteTo;
}

int IO::formattedDate() { 
	// These variables may end up being used to set the day, month, and year values for the Event object
	int day, month, year, formattedDate = 0;

	IO::newLineSpace();
	std::cout << "Please enter the month of your event: ";
	std::cin >> month;

	IO::newLineSpace();
	std::cout << "Please enter the day of your event: ";
	std::cin >> day;

	IO::newLineSpace();
	std::cout << "Please enter the year of your event: ";
	std::cin >> year;

	// Year will be in the form xxxx0000; Month in the form yy00; Day will just be zz
	formattedDate += (year * pow(10, 4));
	formattedDate += (month * pow(10, 2));
	formattedDate += day;

	// Return an integer in the format of xxxxyyzz
	return formattedDate;
}