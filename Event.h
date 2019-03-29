#pragma once
#include <string>

class Event {
	// Name of event, date event occurs, time at which event takes place, how often the event repeats (if it repeats at all)
	std::string name, date, description;
	int time, frequency;
	bool repeat;

public:
	Event();
	Event(std::string _name, std::string _date, std::string _description, int _time, int _frequency, bool _repeat);

	// Refer to: EVENT 1A
	int dateParser();
};