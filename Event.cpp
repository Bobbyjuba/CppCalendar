#include "Event.h"
#include <iostream>
#include <math.h>

Event::Event() : name("name"), date(""), description("description"), time(-1), frequency(-1), repeat(false) {}

Event::Event(std::string _name, std::string _date, std::string _description, int _time, int _frequency, bool _repeat) :
	name(_name), date(_date), description(_description), time(_time), frequency(_frequency), repeat(_repeat) {}