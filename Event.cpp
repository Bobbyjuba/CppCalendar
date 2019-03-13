#include "Event.h"

// Default constructor shouldn't be invoked; at this point in time, I do not have a use for it
Event::Event() : name(""), date(""), time(-1), frequency(-1), repeat(false) {}

Event::Event(std::string _name, std::string _date, int _time, int _frequency, bool _repeat) :
	name(_name), date(_date), time(_time), frequency(_frequency), repeat(_repeat) {}

int Event::dateParser(std::string _date) {

}