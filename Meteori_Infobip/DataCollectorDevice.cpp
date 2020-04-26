#include "DataCollectorDevice.h"
#include "DateTime.h"
#include "Meteor.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> DataCollectorDevice::read_csv_row(std::ifstream& in, char vs)
{
	std::vector<std::string> vec;
	std::string value_container = "";
	for (char c = in.get(); in.good() && c != '\n'; c = in.get())			
	{																	
		if (c == vs)													
		{																
			vec.push_back(value_container);								
			value_container = "";										
		}																
		else															
			value_container += c;										
	}																	
	vec.push_back(value_container);		//necessary because on \n exits loop and never hits last push_back
	return vec;
}

std::vector<std::vector<std::string>> DataCollectorDevice::read_csv_file(std::string file_name, char vs)
{
	std::vector<std::vector<std::string>> vec;
	std::ifstream in(file_name.c_str(), std::ios_base::binary);
	
	for (char c = in.get(); in.good();)
	{
		std::vector<std::string> s = read_csv_row(in, vs);
		vec.push_back(s);
	}
	vec.pop_back();

	return vec;
}

std::vector<Meteor> DataCollectorDevice::collect_meteor_data(std::string file_name, char vs)
{
	std::vector<Meteor> vec;
	std::vector<std::vector<std::string>> vec2 = read_csv_file(file_name, vs);

	for (int i = 1; i < vec2.size(); i++)
	{
		std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
		std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";

		for (int i = 1; i <= 4; i++)
			s_year += vec2[i].at(0)[i];
		for (int i = 5; i <= 6; i++)
			s_month += vec2[i].at(0)[i];
		for (int i = 7; i <= 8; i++)
			s_day += vec2[i].at(0)[i];
		for (int i = 10; i <= 11; i++)
			s_hour += vec2[i].at(0)[i];
		for (int i = 12; i <= 13; i++)
			s_min += vec2[i].at(0)[i];
		for (int i = 14; i <= 15; i++)
			s_sec += vec2[i].at(0)[i];
		s_solar_long = vec2[i].at(1);
		s_RA_geo = vec2[i].at(2);
		s_Decl_geo = vec2[i].at(3);
		s_V_geo = vec2[i].at(4);
		s_V_init = vec2[i].at(5);

		int year, month, day, hour, min, sec;
		double solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial;
		
		year = std::stoi(s_year);
		month = std::stoi(s_month);
		day = std::stoi(s_day);
		hour = std::stoi(s_hour);
		min = std::stoi(s_min);
		sec = std::stoi(s_sec);
		solar_longitude = std::stod(s_solar_long);
		RA_geometric = std::stod(s_RA_geo);
		Decl_geometric = std::stod(s_Decl_geo);
		V_geometric = std::stod(s_V_geo);
		V_initial = std::stod(s_V_init);

		DateTime dateTime(year, month, day, hour, min, sec);
		Meteor new_Loaded_Meteor(dateTime, solar_longitude, RA_geometric, Decl_geometric, V_geometric, V_initial);
		vec.push_back(new_Loaded_Meteor);
	}

	return vec;
}


/*
std::vector<std::vector<std::string>> DataCollectorDevice::return_csv_data(std::string file_name, char vs)
{
	std::vector<std::vector<std::string>> csv_file_data;
	std::ifstream in(file_name.c_str(), std::ios_base::binary);

	if (in.bad())
	{
		std::cout << "file is bad\n";
		return std::vector<std::vector<std::string>>();
	}
	else if (in.fail())
	{
		std::cout << "failed to load file\n";
		return std::vector<std::vector<std::string>>();
	}

	std::vector<std::string> csv_file_row;
	std::string variable_container = "";

	for (char c = in.get(); in.good(); c = in.get())		//loops thought entire file taking all characters
	{
		if (c == vs)										//is char is value seperator
		{													//
			csv_file_row.push_back(variable_container);		//pushes string isto vector with that row
			variable_container = "";						//resets string for new string to be loaded
		}
		else if (c == '\n')									//if char is end of the row
		{													//
			csv_file_row.push_back(variable_container);		//
			csv_file_data.push_back(csv_file_row);			//
			csv_file_row.clear();							//pushs row into data vector
			variable_container = "";						//clears row for new row to be loaded
		}
		else
			variable_container += c;						//is its not value seperator or end of the row, its data so it puts char into string
	}

	return csv_file_data;
}
*/