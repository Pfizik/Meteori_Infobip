#pragma once
#include "DateTime.h"

struct Meteor
{
public:
	DateTime dataTime();
	double solar_longitude;
	double RA_geometric;
	double Decl_geometric;
	double V_geometric;
	double V_initial;
};