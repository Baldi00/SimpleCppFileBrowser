#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

#include "File.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "SongFile.h"
#include "MovieFile.h"
#include "Directory.h"

#pragma region CopyedFromInternet

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

inline bool ends_with(std::string const& value, std::string const& ending)
{
	if (ending.size() > value.size()) return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

#pragma endregion

void recursiveLoad(Directory* root, Directory* parent, std::string rootPath)
{
	std::string command = "dir /b \"" + rootPath + "\"";
	const char* final_command = command.c_str();
	std::string result = exec(final_command);

	if (result.compare("") == 0)
	{
		std::cout << "Directory not found" << std::endl;
		std::cin.get();
		exit(0);
		return;
	}

	std::vector<std::string> resultSplit = split(result, '\n');

	int directoriesCount = 0;
	int filesCount = 0;

	for (std::string current : resultSplit)
	{
		if (current.find(".") == std::string::npos)
			directoriesCount++;
		else if (ends_with(current, ".txt") || ends_with(current, ".jpg")
			|| ends_with(current, ".mp3") || ends_with(current, ".mp4"))
			filesCount++;
	}

	root->Initialize(rootPath, parent, directoriesCount, filesCount);

	for (std::string current : resultSplit)
	{
		std::string currentPath = rootPath + "\\" + current;

		if (current.find(".") == std::string::npos)
		{
			Directory* newDirectory = new Directory();
			recursiveLoad(newDirectory, root, currentPath);
			root->AddDirectory(newDirectory);
		}
		else if (ends_with(current, ".txt"))
		{
			File* newFile = new TextFile(current, currentPath);
			root->AddFile(newFile);
		}
		else if (ends_with(current, ".jpg"))
		{
			File* newFile = new ImageFile(current, currentPath);
			root->AddFile(newFile);
		}
		else if (ends_with(current, ".mp3"))
		{
			File* newFile = new SongFile(current, currentPath);
			root->AddFile(newFile);
		}
		else if (ends_with(current, ".mp4"))
		{
			File* newFile = new MovieFile(current, currentPath);
			root->AddFile(newFile);
		}
	}
}

int main()
{
	std::string rootPath = "TestFolder";
	Directory* root = new Directory();
	recursiveLoad(root, nullptr, rootPath);

	Directory* currentDirectory = root;

	std::string command;
	do {
		std::cout << "\n\nYou are inside " + currentDirectory->GetPath() << std::endl << "Commands: dir, cd name, cd.., open name, search name, exit" << std::endl;
		std::cin >> command;

		if (command.compare("cd") == 0)
		{
			std::string nextDirectoryName;
			std::cin >> nextDirectoryName;
			Directory* nextDirectory = currentDirectory->FindDirectory(nextDirectoryName.c_str());

			if (nextDirectory != nullptr)
				currentDirectory = nextDirectory;
		}
		else if (command.compare("cd..") == 0)
		{
			if (currentDirectory->GetParentDirectory() != nullptr)
				currentDirectory = currentDirectory->GetParentDirectory();
		}
		else if (command.compare("open") == 0)
		{
			std::string fileName;
			std::cin >> fileName;
			File* fileToOpen = currentDirectory->SearchFile(fileName.c_str());
			if (fileToOpen != nullptr)
				fileToOpen->Open();
		}
		else if (command.compare("search") == 0)
		{
			std::string fileName;
			std::cin >> fileName;
			currentDirectory->PrintSearch(fileName.c_str());
		}
		else if (command.compare("dir") == 0)
		{
			currentDirectory->PrintDirectoryContent();
		}

	} while (command.compare("exit") != 0);

	delete root;
	root = nullptr;

	return 0;
}