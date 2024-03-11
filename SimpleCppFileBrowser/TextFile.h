#pragma once

#include "File.h"

class TextFile : public File
{
public:
	TextFile(std::string Name, std::string Path) : File(Name, Path) {};
	TextFile(TextFile& TextFile) : File(TextFile) {};
	~TextFile() {};
	virtual void PrintName() override;
};
