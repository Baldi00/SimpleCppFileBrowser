#pragma once

#include "File.h"

class ImageFile : public File
{
public:
	ImageFile(std::string Name, std::string Path) : File(Name, Path) {}
	ImageFile(ImageFile& ImageFile) : File(ImageFile) {}
	~ImageFile() {};
	virtual void PrintName() override;
};
