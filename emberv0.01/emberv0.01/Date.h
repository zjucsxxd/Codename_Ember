#pragma once

#include <string>

using std::string;

class Date
{
public:
	Date();
	~Date();
	int getDuration()
	{
		return hour * 60 + minute;
	}
private:
	string day;
	int hour;
	int minute;
};

