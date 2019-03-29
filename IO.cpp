#include "IO.h"
#include <algorithm>

std::string IO::stringInitial(std::string strToWriteTo) {
	// ProceedStr will hold the user's string response, and proceed will control the while-loop
	std::string proceedStr;
	bool proceed = false;

	// Refer to: IO 1A + 1B
	if (strToWriteTo == "name") {
		std::cout << "Please give a name for your event: ";
		std::getline(std::cin, strToWriteTo);

		// Let the user keep editing the name until they are satisfied with it
		while (!proceed) {
			std::cout << "Is this name correct \"" << strToWriteTo << "\" ? (Y/N) : ";
			std::getline(std::cin, proceedStr);

			// Convert proceedStr to lowercase for checking purposes
			std::transform(proceedStr.begin(), proceedStr.end(), proceedStr.begin(), ::tolower);

			if (proceedStr == "y" || proceedStr == "yes")
				proceed = true;

			else if (proceedStr == "n" || proceedStr == "no") {
				std::cout << "Please give a name for your event: ";
				std::getline(std::cin, strToWriteTo);
			}

			else
				std::cout << "Unexpected input" << std::endl;
		}
	}

	// This section will execute if the user is adding a description to their event
	// More or less, this code is the same as the code for name
	if (strToWriteTo == "description") {
		std::cout << "Please give a description for your event: " << std::endl;
		std::getline(std::cin, strToWriteTo);

		while (!proceed) {
			std::cout << std::endl << "Is this description correct? \n\"" << strToWriteTo << "\" (Y/N) : ";
			std::getline(std::cin, proceedStr);

			std::transform(proceedStr.begin(), proceedStr.end(), proceedStr.begin(), ::tolower);

			if (proceedStr == "y" || proceedStr == "yes")
				proceed = true;

			else if (proceedStr == "n" || proceedStr == "no") {
				std::cout << std::endl << "Please give a description for your event: " << std::endl;
				std::getline(std::cin, strToWriteTo);
			}

			else
				std::cout << "Unexpected input" << std::endl;
		}
	}

	// Return whichever variable the user edited, so the correlating variable can be set in the Event object
	return strToWriteTo;
}

int IO::formattedDate() {}