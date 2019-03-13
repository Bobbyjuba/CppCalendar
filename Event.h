#pragma once
#include <string>

class Event {
	// Name of event, date event occurs, time at which event takes place, how often the event repeats (if it repeats at all)
	std::string name, date;
	int time, frequency;
	bool repeat;

	Event();
	Event(std::string _name, std::string _date, int _time, int _frequency, bool _repeat);

public:
	// dateParser will convert dates from '00/00/0000' and convert them into an int
	int dateParser(std::string _date);
};