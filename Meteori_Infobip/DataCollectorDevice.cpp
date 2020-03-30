#include "pch.h"
#include "DataCollectorDevice.h"
#include "DateTime.h"
#include "Meteor.h"
#include <fstream>
#include <vector>
#include <string>

void DataCollectorDevice::load_CAMS_data_to(std::vector<Meteor>& CAMS_vec)
{
	CAMS_vec.clear();
	std::ifstream in("");
	in.seekg(0);			//skips words at the start

	int year, month, day, hour, min, sec;
	double solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial;

	std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
	std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";
}

void DataCollectorDevice::load_GNU_data_to(std::vector<Meteor>& GNU_vec)
{
	GNU_vec.clear();
	std::ifstream in("");
	in.seekg(0);			//skips words at the start

	int year, month, day, hour, min, sec;
	double solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial;

	std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
	std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";
}

void DataCollectorDevice::load_EDMOND_data_to(std::vector<Meteor>& EDMOND_vec)
{
	EDMOND_vec.clear();
	std::ifstream in("");
	in.seekg(0);			//skips words at the start

	int year, month, day, hour, min, sec;
	double solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial;

	std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
	std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";
}

void DataCollectorDevice::load_SonotaCo_data_to(std::vector<Meteor>& SonotaCo_vec)
{
	SonotaCo_vec.clear();
	std::ifstream in("data/SonotaCo.csv");
	in.seekg(37);			//skips words at the start

	if (in.bad())
		return;
	else if (in.fail())
		return;

	while (true)
	{
		int year, month, day, hour, min, sec;
		double solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial;

		std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
		std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";

		in.get();
		if (in.eof())
			return;

#pragma region dateTimeCollecting

		for (int i = 0; i < 4; i++)
			s_year += in.get();
		for (int i = 0; i < 2; i++)
			s_month += in.get();
		for (int i = 0; i < 2; i++)
			s_day += in.get();
		in.get();
		for (int i = 0; i < 2; i++)
			s_hour += in.get();
		for (int i = 0; i < 2; i++)
			s_min += in.get();
		for (int i = 0; i < 2; i++)
			s_sec += in.get();
		in.get();

		year = std::stoi(s_year);
		month = std::stoi(s_month);
		day = std::stoi(s_day);
		hour = std::stoi(s_hour);
		min = std::stoi(s_min);
		sec = std::stoi(s_sec);

#pragma endregion getting date and time
		DateTime dateTime(year, month, day, hour, min, sec);

#pragma region dataCollecting

		for (char c = in.get(); in.good() && c != ','; c = in.get())
			s_solar_long += c;
		for (char c = in.get(); in.good() && c != ','; c = in.get())
			s_RA_geo += c;
		for (char c = in.get(); in.good() && c != ','; c = in.get())
			s_Decl_geo += c;
		for (char c = in.get(); in.good() && c != ','; c = in.get())
			s_V_geo += c;
		for (char c = in.get(); in.good() && c != '\n'; c = in.get())
			s_V_init += c;

		solar_longitude = std::stod(s_solar_long);
		RA_geometric = std::stod(s_RA_geo);
		Decl_geometric = std::stod(s_Decl_geo);
		V_geometric = std::stod(s_V_geo);
		V_initial = std::stod(s_V_init);

#pragma endregion getting sol_long, ra_geo, decl_geo, v_geo, v_init
		Meteor new_Loaded_Meteor(dateTime, solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial);

		SonotaCo_vec.push_back(new_Loaded_Meteor);
	}
}