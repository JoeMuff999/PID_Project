
#include <math.h>
#include "../headers/Vector.hh"

double Math::Vector::Vmag(double vector[3])
{
    double mag = vector[0] * vector[0];
    mag += vector[1] * vector[1];
    mag += vector[2] * vector[2];

    mag = sqrt(mag);
    return mag;
}
double* Math::Vector::crossProduct(double vector1[3], double vector2[3])
{
    crossP[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    crossP[1] = vector1[0] * vector2[2] - vector1[2] * vector2[0];
    crossP[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return crossP;
}
