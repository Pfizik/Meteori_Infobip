#pragma once
#include "DateTime.h"

class Meteor
{
public:
	Meteor(DateTime dataTime, double solar_longitude, double RA_geometric, double Decl_geometric, double V_geometric, double V_initial);
public:
private:
	DateTime dataTime;
	double solar_longitude;
	double RA_geometric;
	double Decl_geometric;
	double V_geometric;
	double V_initial;
};