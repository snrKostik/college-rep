#pragma once

#include <print>
using namespace std;

void Linear();
void Binary();
void Advanced();

void Find() {
  Linear();
  Binary();
  Advanced();
}

inline void Linear() { println("linear"); }
inline void Binary() { println("Binary"); }
inline void Advanced() { println("Advanced Binary"); }
