/*
PURPOSE: (record satellite k values for monte usage)
*/
#ifndef K_H
#define K_H

#include "../models/ISS/headers/satellite.h"

class kValueStorage {
public:
  double storagekP;
  double storagekI;
  double storagekD;
};
#endif
