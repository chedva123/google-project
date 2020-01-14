#include "Online.h"
#define SIZE 5
static string letterStr ="1234567890abcdefghijklmnopqrstuvwxyz _";
const int arrPunishAddOrSub[] = { 10,8,6,4,2 };
const int arrPunishReplace[] = { 5,4,3,2,1 };

int punishAddOrSub(int idx) {
	return idx<4?arrPunishAddOrSub[idx]: arrPunishAddOrSub[4];
	
}
int punishReplace(int idx) {
	return idx < 4 ? arrPunishReplace[idx]:arrPunishReplace[4];
}
bool isVectorFull(std::vector<AutoCompleteData>& write) {
	return write.size() == SIZE;
}
void parsePrefix(string & prefix) {
	//regex re("\\s{2,}");
	regex re("[\\W]+[\\s]*");
	prefix = (regex_replace(prefix, re, " "));
	std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
}
void vectorWrite(std::vector<AutoCompleteData>& write, std::vector<pair<string, int >> &read, int score) {
	int idx = 0;
	for (; write.size() <SIZE && idx < read.size(); ++idx)
	{
		string fileName = read[idx].first;
		int offset = read[idx].second;
		string compSentence = DataFile::getLineByNameFile(fileName, offset);
		write.push_back(AutoCompleteData(compSentence, fileName, offset, score));
	}
}

void checkAndWrite(std::vector<AutoCompleteData> &write, const string& key, int score) {
	if (getMap().find(key) != getMap().end())
		vectorWrite(write, getMap()[key], score);

}
void scoreOfAdd(std::vector<AutoCompleteData> &write, const string &prefix) {
	int score;
	string toCheck = prefix;
	int lenPrefix = prefix.length();
	for (int i = lenPrefix; i >= 0; --i) {
		toCheck = prefix;
		for (auto letter : letterStr) {
			if (letter != prefix[i]) {

				toCheck.insert(i, 1, letter);
				score = lenPrefix * 2 - punishAddOrSub(i);
				checkAndWrite(write, toCheck, score);
			}
			if (isVectorFull(write))
				return;
		}
	}
}

void scoreOfReplace(std::vector<AutoCompleteData> &write, const string &prefix) {
	int score;
	string toCheck = prefix;
	string tmp;
	int lenPrefix = prefix.length();
	for (int i = lenPrefix - 1; i >= 0; --i) {
		toCheck = prefix;
		for (auto letter : letterStr) {
			if (letter != prefix[i]) {

				toCheck.replace(i, 1, tmp+=letter);
				score = (lenPrefix - 1) * 2 - punishReplace(i);
				checkAndWrite(write, toCheck, score);
			}
			if (isVectorFull(write))
				return;
		}
	}
}


void scoreOfSub(std::vector<AutoCompleteData> &write, const string &prefix) {
	int score;
	string toCheck = prefix;
	int lenPrefix = prefix.length();
	for (int i = lenPrefix; i >= 0; --i) {
		toCheck = prefix;
		toCheck.erase(i, 1);
		score = lenPrefix * 2 - punishAddOrSub(i);
		checkAndWrite(write, toCheck, score);
		if (isVectorFull(write))
			return;
	}
}
std::vector<AutoCompleteData> GetBestKCompletions(const string& prefix) {
	std::vector<AutoCompleteData> autoCompleteData;
	checkAndWrite(autoCompleteData, prefix, prefix.length() * 2);
	if (isVectorFull(autoCompleteData) )
		return autoCompleteData;
	scoreOfReplace(autoCompleteData, prefix);
	if (isVectorFull(autoCompleteData) )
		return autoCompleteData;
	scoreOfSub(autoCompleteData, prefix);
	if (isVectorFull(autoCompleteData) )
		return autoCompleteData;
	scoreOfAdd(autoCompleteData, prefix);
	if (isVectorFull(autoCompleteData) )
		return autoCompleteData;
	return autoCompleteData;
}

void run()
{
	string prefix;
	std::vector<AutoCompleteData> autoCompleteData;
	while (true)
	{
		autoCompleteData.clear();
		std::cout << "serch: \n";
		std::cin >> prefix;
		if (prefix == "exit()")
			exit(0);
		parsePrefix(prefix);
		std::cout <<prefix<< "\n";
		autoCompleteData = GetBestKCompletions(prefix);
		std::cout << autoCompleteData.size() << "\n";
		for (int i = 0; i < autoCompleteData.size(); ++i)
			std::cout << autoCompleteData[i].getCompletedSentence() << ' ';
		std::cout << '\n';
	}
}