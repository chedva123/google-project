#pragma once
#include <iostream>
using std::string;

class AutoCompleteData
{
public:
	AutoCompleteData
	(string  completed_sentence, string  source_text, int offset, int score);
	~AutoCompleteData();
	const string &getCompletedSentence()  {
		return completed_sentence;
	}

	const string &getSourceText() const {
		return source_text;
	}

	int getScore() const {
		return score;
	}
	int getOffset() const {
		return offset;
	}
	void setScore(int i) {
		this->score=i;
	}
	friend std::ostream & operator<<(std::ostream &out, const AutoCompleteData &c);
private:
	string completed_sentence;
	string source_text;
	int offset;
	int score;
};



