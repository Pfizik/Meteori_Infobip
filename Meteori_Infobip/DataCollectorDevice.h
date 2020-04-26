#pragma once
#include <vector>
#include <string>
#include "Meteor.h"

class DataCollectorDevice
{
public:
	std::vector<Meteor> collect_meteor_data(std::string file_name, char value_seperator);
	//std::vector<std::vector<std::string>> return_csv_data(std::string file_name, char value_seperator);
private:
	std::vector<std::string> read_csv_row(std::ifstream& input_fstream, char value_seperator);
	std::vector<std::vector<std::string>> read_csv_file(std::string file_name, char value_seperator);

};