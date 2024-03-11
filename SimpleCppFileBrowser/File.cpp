#include "File.h"
#include <iostream>

void File::PrintName()
{
	std::cout << "File: " << Name << std::endl;
}

void File::Open()
{
	system(Path.c_str());
}

bool File::NameContains(std::string Search)
{
	std::string MyName = Name;
	return MyName.find(Search) != std::string::npos;
}
