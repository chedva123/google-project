#pragma once



#include "DataFile.h"

using std::pair;

//static std::unordered_map<string, std::vector<AutoCompleteData>> keysAndSentences;
 struct OffLine
{
	static std::unordered_map<string, std::vector<pair<string, int >>> keysAndSentences;//value=namefile,number_line

};
static std::unordered_map<string, std::vector<pair<string, int >>>& getMap() {
	return OffLine::keysAndSentences;
}
string getParam(string& line);
/*void insertToMap(string lineToParse)
{
	string key, srcTxt, offset, compSent;
	key = getParam(lineToParse);
	srcTxt = getParam(lineToParse);
	offset = getParam(lineToParse);
	compSent = getParam(lineToParse);
	if (keysAndSentences.find(key) == keysAndSentences.end()) {
		std::vector<AutoCompleteData> tmp;
		keysAndSentences[key] = tmp;
	}
	AutoCompleteData autoCompleteData(compSent,srcTxt, std::stoi( offset),key.length()*2);
	keysAndSentences[key].push_back(autoCompleteData);
}*/
void insertMapDataFile(string &fileName);
void insertMapKeysAndSentences(string key, string fileName, int lineInFile);
void insertToMaps(string& lineToParse);
void init();


//static std::unordered_map<string, Data*> Data;





