
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
