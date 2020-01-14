#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::string;
using std::cout;

class DataFile
{
public:
	DataFile(std::string fileName);
	~DataFile();
	std::vector<string> getDatafile(std::string fileName);
	void addMap(std::string fileName, std::vector<string> line);
	static std::string getLineByNameFile(std::string fileName, int i);
	static std::unordered_map<string, std::vector<string>>& getFilesLines() {
		return filesLines;
	}
private:
	static std::unordered_map<string,std::vector<string>> filesLines;

};

