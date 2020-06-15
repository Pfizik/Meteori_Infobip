#include "FileFormater.h"
#include <string>
#include <fstream>

void format_file_remove_backslash_r(std::string file_name, std::string new_file_name)
{
	std::ifstream in(file_name.c_str(), std::ios_base::binary);
	std::ofstream out(new_file_name.c_str(), std::ios_base::binary);

	for (char c = in.get(); in.good(); c = in.get())
	{
		if (c != '\r')
			out.put(c);
	}
}

void format_file_change_char_seperator(std::string file_name, std::string new_file_name, char ocs, char ncs)
{
	std::ifstream in(file_name.c_str(), std::ios_base::binary);
	std::ofstream out(new_file_name.c_str(), std::ios_base::binary);

	for (char c = in.get(); in.good(); c = in.get())
	{
		if (c != ocs)
			out.put(c);
		else
			out.put(ncs);
	}
}
