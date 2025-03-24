#include "D:/.mylibs/lifeEasier.hpp"

#pragma once

static int charCount = 0;
class IStringAnalyzer {
private:
public:
  virtual int analyse(string str) = 0;
};

#define IstrAn IStringAnalyzer