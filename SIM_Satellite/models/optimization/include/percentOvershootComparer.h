/*
PURPOSE: (ts98 comparison object for std::sort)
*/
#ifndef POCOMPARER_H
#define POCOMPARER_H
#include <cstdio>
#include <vector>
#include <iostream>

#include "score.h"
// this is super cool but i dont get it to be honest
class comparerPercentOvershoot {
public:
  inline bool operator() (const Score& a, const Score& b)
  {
  return(a.meanPercentOvershoot < b.meanPercentOvershoot);
  }
};
#endif
