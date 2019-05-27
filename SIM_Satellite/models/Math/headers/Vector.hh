#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>

namespace Math
{
    class Vector
    {
        public:
        double crossP[3];
        static double Vmag( double vector[3] );
        double* crossProduct(double vector1[3], double vector2[3]);
    };
}
#endif
