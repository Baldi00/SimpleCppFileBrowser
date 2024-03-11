#pragma once
#include <iostream>

class File
{
protected:
	std::string Name;
	std::string Path;

public:
	File()
		: Name("")
		, Path("")
	{}

	File(std::string Name, std::string Path)
		: Name(Name)
		, Path(Path)
	{}

	File(File& OtherFile)
		: Name(OtherFile.Name)
		, Path(OtherFile.Path)
	{}

	~File()
	{}

	virtual void PrintName();
	virtual void Open();

	bool NameContains(std::string Search);
};