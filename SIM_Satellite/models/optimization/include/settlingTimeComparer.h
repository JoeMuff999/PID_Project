/*
PURPOSE: (ts98 comparison object for std::sort)
*/
#ifndef TS98COMPARER_H
#define TS98COMPARER_H
#include <cstdio>
#include <vector>
#include <iostream>

#include "score.h"
// this is super cool but i dont get it to be honest
class comparerSettlingTime {
public:
  inline bool operator() (const Score& a, const Score& b)
  {
  return(a.meanSettlingTime < b.meanSettlingTime);
  }
};
#endif
