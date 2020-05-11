#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::vector<std::string>> file_checker(std::vector<std::vector<std::string>>& csv_file_data, std::ifstream& in) {
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
}