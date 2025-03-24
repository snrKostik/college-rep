#include "../lib/lifeEasier.hpp"
// #include <cstdlib>
#include <random>
#include "Windows.h"


inline int generateNumber(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 14);

  return distrib(gen);
}

inline string generateMast(){
  std::random_device rd;
	std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 3);

  int Mast = distrib(gen);
  switch(Mast){
    case 0: return "\u2665";
    case 1: return "\u2666";
    case 2: return "\u2663";
    case 3: return "\u2660";
  }//?♥♦♣♠

  return "";
}  

inline void cache(string arr, int size){

}