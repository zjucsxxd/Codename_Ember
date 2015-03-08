#pragma once

#include <vector>

#include "Project.h"

using std::vector;

class Calendar
{
	friend Project;
public:
	Calendar();
	~Calendar();
private:
	vector<Project> projects;
};

