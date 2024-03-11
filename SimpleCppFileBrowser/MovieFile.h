#pragma once

#include "File.h"

class MovieFile : public File
{
public:
	MovieFile(std::string Name, std::string Path) : File(Name, Path) {};
	MovieFile(MovieFile& MovieFile) : File(MovieFile) {};
	~MovieFile() {};
	virtual void PrintName() override;
};
