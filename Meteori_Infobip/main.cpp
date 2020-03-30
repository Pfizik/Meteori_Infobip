#include "pch.h"
#include <iostream>
#include <vector>
#include "Meteor.h"
#include "DataCollectorDevice.h"

int main()
{
	std::vector<Meteor> v;
	DataCollectorDevice dcd;
	dcd.load_SonotaCo_data_to(v);
}