#include "DateTime.h"

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
	:
	year(year),
	month(month),
	day(day),
	hour(hour),
	minute(minute),
	second(second)
{
}

int DateTime::Year()
{
	return year;
}

int DateTime::Month()
{
	return month;
}

int DateTime::Day()
{
	return day;
}

int DateTime::Hour()
{
	return hour;
}

int DateTime::Minute()
{
	return minute;
}

int DateTime::Second()
{
	return second;
}