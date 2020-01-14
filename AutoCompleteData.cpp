#include "AutoCompleteData.h"



AutoCompleteData::AutoCompleteData
(string  completed_sentence, string  source_text, int offset, int score)
	: completed_sentence(std::move(completed_sentence)),
	source_text(std::move(source_text)), offset(offset), score(score) {}


AutoCompleteData::~AutoCompleteData()
{
}

