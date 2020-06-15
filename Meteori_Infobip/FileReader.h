#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void file_reader(std::vector<std::vector<std::string>>& csv_file_data, std::vector<std::string>& csv_file_row, std::string variable_container, std::string& file_name, char& vs, std::ifstream& in) {
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
		else if (c == '\r')									//screw \r breaking my code, get the f out of here
		{
		}
		else
			variable_container += c;						//is its not value seperator or end of the row, its data so it puts char into string
	}
}