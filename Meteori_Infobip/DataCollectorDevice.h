#pragma once
#include <vector>
#include <string>
#include "Meteor.h"

class DataCollectorDevice
{
public:
	std::vector<std::vector<std::string>> return_csv_data(std::string file_name, char value_seperator);
};