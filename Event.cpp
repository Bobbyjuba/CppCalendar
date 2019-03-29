#include "Event.h"
#include <iostream>
#include <math.h>

Event::Event() : name("name"), date(""), description("description"), time(-1), frequency(-1), repeat(false) {}

Event::Event(std::string _name, std::string _date, std::string _description, int _time, int _frequency, bool _repeat) :
	name(_name), date(_date), description(_description), time(_time), frequency(_frequency), repeat(_repeat) {}

// Refer to: EVENT 1A
int Event::dateParser() {
	int day, month, year, formattedDate = 0;

	std::cout << "Please enter the month of your event: ";
	std::cin >> month;

	// Make month into a xx000000 format
	formattedDate += (month * pow(10, 6));

	std::cout << "Please enter the day of your event: ";
	std::cin >> day;

	// Make day into a yy0000 format
	formattedDate += (day * pow(10, 4));

	// Add year as the final four digits of formattedDate
	std::cout << "Please enter the year of your event: ";
	std::cin >> year;

	// Return an integer in the format of xxyyzzzz
	return (formattedDate += year);
}