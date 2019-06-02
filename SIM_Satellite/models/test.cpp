#include <iostream>
#include "Math/headers/Vector.hh"
#include "Math/headers/Vector.cpp"

using namespace std;

int main()
{
  double pi = M_PI;
  double eToS[3];
  double sToE[3];
  double pyr[3];  // alpha  = 0, beta = 1, gamma = 2
  Math::Vector test;
  pyr[0] = pi/2;
  pyr[1] = 0;
  pyr[2] =0;

  eToS[0] = 5;
  eToS[1] = 10;
  eToS[2] = 20;
  double pos_Mag = 0;
  for(int i = 0; i < 3; i++)
  {
    pos_Mag += eToS[i]*eToS[i];
  }
  pos_Mag = sqrt(pos_Mag);
  sToE[0] = eToS[0]/pos_Mag;
  sToE[1] = eToS[1]/pos_Mag;
  sToE[2] = -eToS[2]/pos_Mag;
std::cout << sToE[1];

  sToE[0] = (sToE[0] * cos(pyr[2])*cos(pyr[1])) + (sToE[1] * sin(pyr[2])*cos(pyr[1])) + (sToE[2]*-1*sin(pyr[1]));
  sToE[1] = (sToE[0]* (cos(pyr[2])*sin(pyr[1])*sin(pyr[0])-sin(pyr[2])*cos(pyr[0]))) + (sToE[1]*(sin(pyr[2])*sin(pyr[1])*sin(pyr[0])+cos(pyr[2])*cos(pyr[0])))
   + (sToE[2]*cos(pyr[1])*sin(pyr[0]));
  sToE[2] = (sToE[0]*(cos(pyr[2])*sin(pyr[1])*cos(pyr[0])+sin(pyr[2])*sin(pyr[0]))) + (sToE[1]*(sin(pyr[2])*sin(pyr[1])*cos(pyr[0])-cos(pyr[2])*sin(pyr[0])))
  +(sToE[2]*cos(pyr[1])*cos(pyr[0]));



  std::cout << "sToE (FCD)" << sToE[0] << " , " << sToE[1] << " , " << sToE[2];




  //double* cross = test.crossProduct(vector, vector2);


  return 0;
}
