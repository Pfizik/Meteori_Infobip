#include <iostream>
#include <vector>
#include <string>
#include "Meteor.h"
#include "DataCollectorDevice.h"

int main()
{
	std::vector<Meteor> v;
	std::vector<std::vector<std::string>> v2;
	DataCollectorDevice dcd;
	v2 = dcd.return_csv_data("data/EDMONDv5.csv", ',');
}