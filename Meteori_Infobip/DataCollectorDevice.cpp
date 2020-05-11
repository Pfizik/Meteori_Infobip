#include "DataCollectorDevice.h"
#include "DateTime.h"
#include "Meteor.h"
#include "FileReader.h"
#include "FileChecker.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::vector<std::string>> DataCollectorDevice::return_csv_data(std::string file_name, char vs)
{
	std::vector<std::vector<std::string>> csv_file_data;
	std::ifstream in(file_name.c_str(), std::ios_base::binary);

	file_checker(csv_file_data, in);

	std::vector<std::string> csv_file_row;
	std::string variable_container = "";

	file_reader(csv_file_data, csv_file_row, variable_container, file_name, vs, in);

	return csv_file_data;
}