#pragma once

#include "stdafx.h"
#include <string>
#include <map>

typedef std::map<std::string, int> StrIntMap;
void CountWords(std::string InputStr, StrIntMap& Words);
