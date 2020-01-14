#include "OffLine.h"
std::unordered_map<string, std::vector<pair<string, int >>>OffLine:: keysAndSentences;
string getParam(string & line)
{
	string param = line.substr(0, line.find(';'));
	line = line.substr(line.find(';') + 1);
	return param;
}

void insertMapDataFile(string & fileName)
{
	if (DataFile::getFilesLines().find(fileName) == DataFile::getFilesLines().end()) {
		DataFile datafile(fileName);
	}
}

void insertMapKeysAndSentences(string key, string fileName,int lineInFile)
{
	

	if (getMap().find(key) == getMap().end()) {
		std::vector<pair<string, int >> tmp;
		getMap()[key] = tmp;
	}
	getMap()[key].push_back(pair<string, int>(fileName, lineInFile));
}

void insertToMaps(string &lineToParse)
{
	string key, fileName;
	int lineInFile;
	key = getParam(lineToParse);
	fileName = getParam(lineToParse);
	lineInFile = stoi(lineToParse);
	insertMapDataFile(  fileName);

	insertMapKeysAndSentences(key, fileName, lineInFile);
	
}

void init()
{
	string line;
	std::ifstream fileData("fileData.txt");
	if (fileData.is_open())
	{
		while (std::getline(fileData, line))
		{
			insertToMaps(line);
		}
		fileData.close();
	}

	else cout << "Unable to open file";

}
