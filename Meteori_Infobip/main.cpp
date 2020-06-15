#include <iostream>
#include <vector>
#include <string>
#include "Meteor.h"
#include "DataCollectorDevice.h"
#include "Tester.h"

int main()
{
	std::vector<Meteor> v;
	std::vector<std::vector<std::string>> v2;
	DataCollectorDevice dcd;
	v = dcd.collect_meteor_data("data/EDMONDv5.csv", ',');
}