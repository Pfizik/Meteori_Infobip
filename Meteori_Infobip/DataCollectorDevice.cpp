#include "DataCollectorDevice.h"
#include "DateTime.h"
#include "Meteor.h"
#include "FileFormater.h"
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

DateTime DataCollectorDevice::string_to_dateTime(std::string string_cell)
{
	DateTime dataTime;

	std::string s_year, s_month, s_day, s_hour, s_min, s_sec = "";
	int year, month, day, hour, min, sec;

	s_year += string_cell.substr(1, 4);
	s_month += string_cell.substr(5, 6);
	s_day += string_cell.substr(7, 8);
	s_hour += string_cell.substr(10, 11);
	s_min += string_cell.substr(12, 13);
	s_sec += string_cell.substr(14, 15);

	dataTime.year = std::stoi(s_year);
	dataTime.month = std::stoi(s_month);
	dataTime.day = std::stoi(s_day);
	dataTime.hour = std::stoi(s_hour);
	dataTime.min = std::stoi(s_min);
	dataTime.sec = std::stoi(s_sec);

	return dataTime;
}

std::vector<Meteor> DataCollectorDevice::collect_meteor_data(std::string file_name, char vs)
{
	std::vector<Meteor> MeteorVec;
	std::vector<std::vector<std::string>> File = read_csv_file(file_name, vs);

	for (int i = 1; i < File.size(); i++)
	{
		std::string s_solar_long, s_RA_geo, s_Decl_geo, s_V_geo, s_V_init = "";

		Meteor meteor;
		meteor.dataTime = string_to_dateTime(File[i].at(0));

		s_solar_long = File[i].at(1);
		s_RA_geo = File[i].at(2);
		s_Decl_geo = File[i].at(3);
		s_V_geo = File[i].at(4);
		s_V_init = File[i].at(5);		
		
		meteor.solar_longitude = std::stod(s_solar_long);
		meteor.RA_geometric = std::stod(s_RA_geo);
		meteor.Decl_geometric = std::stod(s_Decl_geo);
		meteor.V_geometric = std::stod(s_V_geo);
		meteor.V_initial = std::stod(s_V_init);
		
		MeteorVec.push_back(meteor);
	}

	return MeteorVec;
}


/*
std::vector<std::vector<std::string>> DataCollectorDevice::return_csv_data(std::string file_name, char vs)
{
	std::vector<std::vector<std::string>> csv_file_data;
	std::ifstream in(file_name.c_str(), std::ios_base::binary);

	file_checker(csv_file_data, in);

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