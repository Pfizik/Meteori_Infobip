#pragma once
#include <vector>
#include "Meteor.h"

class DataCollectorDevice
{
public:
	void load_CAMS_data_to(std::vector<Meteor>& CAMS_vec);
	void load_GNU_data_to(std::vector<Meteor>& GNU_vec);
	void load_EDMOND_data_to(std::vector<Meteor>& EDMOND_vec);
	void load_SonotaCo_data_to(std::vector<Meteor>& SonotaCo_vec);
};