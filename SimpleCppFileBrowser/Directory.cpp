#include "Directory.h"

Directory::Directory()
{
	Path = "";
	InsideDirectories = nullptr;
	InsideDirectoriesSize = 0;
	InsideDirectoriesCount = 0;
	InsideFiles = nullptr;
	InsideFilesSize = 0;
	InsideFilesCount = 0;
}

Directory::~Directory()
{
	if (InsideDirectories != nullptr)
	{
		delete[] InsideDirectories;
		InsideDirectories = nullptr;
	}

	if (InsideFiles != nullptr)
	{
		delete[] InsideFiles;
		InsideFiles = nullptr;
	}
}

void Directory::Initialize(std::string Path, Directory* Parent, int InsideDirectoriesSize, int InsideFilesSize)
{
	this->Path = Path;
	this->Parent = Parent;

	this->InsideDirectoriesSize = InsideDirectoriesSize;
	InsideDirectories = new Directory * [InsideDirectoriesSize];

	this->InsideFilesSize = InsideFilesSize;
	InsideFiles = new File * [InsideFilesSize];
}

void Directory::AddDirectory(Directory* NewDirectory)
{
	if (InsideDirectoriesCount < InsideDirectoriesSize)
	{
		InsideDirectories[InsideDirectoriesCount] = NewDirectory;
		InsideDirectoriesCount++;
	}
}

void Directory::AddFile(File* NewFile)
{
	if (InsideFilesCount < InsideFilesSize)
	{
		InsideFiles[InsideFilesCount] = NewFile;
		InsideFilesCount++;
	}
}

void Directory::PrintDirectoryContent()
{
	std::cout << Path << std::endl;

	for (int i = 0; i < InsideFilesCount; i++)
		InsideFiles[i]->PrintName();

	for (int i = 0; i < InsideDirectoriesCount; i++)
	{
		std::cout << std::endl;
		InsideDirectories[i]->PrintDirectoryContent();
	}
}

File* Directory::SearchFile(const char* Search)
{
	for (int i = 0; i < InsideFilesCount; i++)
		if (InsideFiles[i]->NameContains(Search))
			return InsideFiles[i];
	return nullptr;
}

void Directory::PrintSearch(const char* Search)
{
	for (int i = 0; i < InsideFilesCount; i++)
		if (InsideFiles[i]->NameContains(Search))
			InsideFiles[i]->PrintName();

	for (int i = 0; i < InsideDirectoriesCount; i++)
		InsideDirectories[i]->PrintSearch(Search);
}

std::string Directory::GetPath()
{
	return Path;
}

Directory* Directory::FindDirectory(const char* Search)
{
	for (int i = 0; i < InsideDirectoriesCount; i++)
		if (InsideDirectories[i]->GetPath().find(Search) != std::string::npos)
			return InsideDirectories[i];
	return nullptr;
}

Directory* Directory::GetParentDirectory()
{
	return Parent;
}
