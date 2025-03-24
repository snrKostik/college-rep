#ifndef LIFEEASIER_HPP
#define LIFEEASIER_HPP
#pragma once

#include <array>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#define print std::cout
#define scan std::cin
#define chr char
#define vector std::vector
#define horizontalSep chr(179)  // ?
#define verticalSep chr(196)    // ?
#define verticalSepRu '-'
#define horizontalSepRu '|'
#define scanIgnoreMax std::numeric_limits<std::streamsize>::max()
#define ruloc std::setlocale(LC_ALL, "Russian")
constexpr char e = '\n';
constexpr char tab = '\t';
using std::string, std::to_string, std::string, std::to_string;
using std::unique_ptr, std::shared_ptr, std::make_unique;

inline void separator(const int n, const chr symbol) {
  print << e;
  for (int i{0}; i <= n; i++) {
    print << symbol;
  }
  print << e;
}

//-----------------------------------

namespace Esc {
  static string ESC = "\033";
  static string eraseLine = ESC + "[2K";
  static string cursorUp = ESC + "[1A";
  static string cursorDown = ESC + "[1D";
  static string untilEnd = ESC + "[0J";
  static string cursorHome = ESC + "[H";
  static string cursorlnHome = ESC + "[0G";

  static string upLines(int num){
    return ESC + "[" + to_string(num) + "A";
  }
} // namespace Esc

#define ESC Esc::ESC

static string clear = ESC + "[0m";
static string bold = ESC + "[1m";
namespace Color {

  namespace Fore {
    static string error = ESC + "[38;2;255;127;127m";
    static string critError = bold + ESC + "[38;2;255;64;64m";
    static string info = ESC + "[38;2;255;212;106m";
    static string log = ESC + "[38;2;75;75;75m";
    static string success = ESC + "[38;2;120;255;120m";
    static string custom(short r, short g, short b, bool isBold) {
      if (isBold == true) {
        return bold + ESC + "[38;2;" + to_string(r) + ";"
               + to_string(g) + ";" + to_string(b) + "m";
      } else {
        return ESC + "[38;2;" + to_string(r) + ";"
               + to_string(g) + ";" + to_string(b) + "m";
      }
    }
  } // namespace Fore

  namespace Back {
    static string a = ESC + "[48;2;0;0;0m";
  }
} // namespace Color

#define Err Color::Fore::error
#define Crit Color::Fore::critError
#define Info Color::Fore::info
#define Clr clear
#define Bold bold
#define Log Color::Fore::log
#define Success Color::Fore::success

inline string scanFail = Err + "Wrong type!" + Clr;

inline int Scan(int value){
  while (true){
    scan >> value;
    if (scan.fail())
    {
      scan.clear();
      scan.ignore(scanIgnoreMax, e);
      print << Err << scanFail << Clr;
      scan >> value;
    } else{
      scan.clear();
      scan.ignore(scanIgnoreMax, e);
      break;
    }
  }
  return value;
}

inline double Scan(double value) {
  while (true){
    scan >> value;
    if (scan.fail())
    {
      scan.clear();
      scan.ignore(scanIgnoreMax, e);
      print << Err << scanFail << Clr;
      scan >> value;
    } else{
      scan.clear();
      scan.ignore(scanIgnoreMax, e);
      break;
    }
  }
  return value;
}
static string stringScanError = "invalid string input. Try again: ";
inline string Scan(string value) {
  while (true){
    std::getline(scan, value);
    if (scan.fail() || value.empty()) {
      scan.clear();
      scan.ignore(scanIgnoreMax, e);
      print << Err << stringScanError << Clr << e;
    } else
      break;
  }
  return value;
}
#endif