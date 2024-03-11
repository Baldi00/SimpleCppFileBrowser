#pragma once

#include "File.h"

class SongFile : public File
{
public:
	SongFile(std::string Name, std::string Path) : File(Name, Path) {};
	SongFile(SongFile& SongFile) : File(SongFile) {};
	~SongFile() {};
	virtual void PrintName() override;
};
