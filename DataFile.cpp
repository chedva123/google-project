#include "DataFile.h"
std::unordered_map<string, std::vector<string>>DataFile::filesLines;
DataFile::DataFile(std::string fileName)
{
	string line;
	std::ifstream fileData(fileName+".txt");
	if (fileData.is_open())
	{
		std::vector<string> tmp;
		while (std::getline(fileData, line))
		{
			tmp.push_back(line);
		}
		fileData.close();
		addMap(fileName, tmp);

	}

	else std::cout << "Unable to open file";
}

DataFile::~DataFile()
{
}

std::vector<string> DataFile::getDatafile(std::string fileName)
{
	
		return filesLines[fileName];
	
}

void DataFile::addMap(std::string fileName, std::vector<string> line)
{
	
		filesLines[fileName] = line;
	
}

std::string DataFile::getLineByNameFile(std::string fileName, int i)
{
	
		return filesLines[fileName][i];
	
}
