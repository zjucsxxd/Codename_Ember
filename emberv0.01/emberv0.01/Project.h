#pragma once

#include <vector>

#include "Event.h"

using std::vector;

class Project
{
	friend Event;
public:
	Project();
	~Project();
private:
	vector<Event> events;
};

