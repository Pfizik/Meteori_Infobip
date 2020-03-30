#include "pch.h"
#include "Meteor.h"

Meteor::Meteor(DateTime dataTime, double solar_longitude, double RA_geometric, double Decl_geometric, double V_geometric, double V_initial)
	:
	dataTime(dataTime),
	solar_longitude(solar_longitude),
	RA_geometric(RA_geometric),
	Decl_geometric(Decl_geometric),
	V_geometric(V_geometric),
	V_initial(V_initial)
{
}