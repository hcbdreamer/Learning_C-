#include<iostream>
#include"mytime0.h"

Time::Time()
{
	minutes = 0;
	hours = 0;
}

Time::Time(int h, int m)
{
	minutes = m;
	hours = h;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::Sum(const Time & t)const
{
	Time Sum;
	Sum.minutes = minutes + t.minutes;
	Sum.hours = hours + t.hours + Sum.minutes / 60;
	Sum.minutes %= 60;
	return Sum;
}

void Time::show() const
{
	std::cout << hours << " hours" << minutes << " minutes" << std::endl;
}