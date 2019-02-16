/*
PURPOSE: (overall comparison object for std::sort)
*/
#ifndef OVERALLCOMPARER_H
#define OVERALLCOMPARER_H
#include <cstdio>
#include <vector>
#include <iostream>

#include "score.h"
// this is super cool but i dont get it to be honest
class comparerOverallRank {
public:
  inline bool operator() (const Score& a, const Score& b)
  {
  return(a.overallRank < b.overallRank);
  }
};
#endif
