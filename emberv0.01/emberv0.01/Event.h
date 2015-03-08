#pragma once

#include "Date.h"

#include <string>

using std::string;

class Event
{
	friend Date;
public:
	Event(){}
	~Event(){}
private:
	Date endTime;
	Date startTime;
	string location;
	string description;
};

