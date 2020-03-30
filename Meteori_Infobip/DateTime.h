#pragma once

class DateTime
{
public:
	DateTime(int year, int month, int day, int hour, int minute, int second);
public:
	int Year();
	int Month();
	int Day();

	int Hour();
	int Minute();
	int Second();
private:
	int year;
	int month;
	int day;

	int hour;
	int minute;
	int second;
};