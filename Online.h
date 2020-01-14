#pragma once
#include "OffLine.h"
#include "AutoCompleteData.h"
#include <regex>
using std::regex;

std::vector<AutoCompleteData> GetBestKCompletions(const string& prefix);
void run();

