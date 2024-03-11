#pragma once

#include "File.h"

class Directory
{
private:
	std::string Path;
	Directory* Parent;

	Directory** InsideDirectories;
	int InsideDirectoriesSize;
	int InsideDirectoriesCount;

	File** InsideFiles;
	int InsideFilesSize;
	int InsideFilesCount;

public:
	Directory();
	~Directory();

	void Initialize(std::string Path, Directory* Parent, int InsideDirectoriesCount, int InsideFilesCount);
	void AddDirectory(Directory* NewDirectory);
	void AddFile(File* NewFile);
	void PrintDirectoryContent();
	File* SearchFile(const char* Search);
	void PrintSearch(const char* Search);
	std::string GetPath();
	Directory* FindDirectory(const char* Search);
	Directory* GetParentDirectory();
};
