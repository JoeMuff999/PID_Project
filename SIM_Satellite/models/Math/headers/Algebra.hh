
namespace Math
{
    class Algebra
    {
        public:
        static double pow_int( double val, int pow );
    };
}

inline double Math::Algebra::pow_int( double val, int pow )
{
    double ret = 1;
    if(pow > 0 )
    {
        ret = val;
        for(int ii=1; ii<pow; ii++)
        {
            ret *= val;
        }
    }
    else // pow < 0
    {
        ret = 1.0/val;
        for(int ii=-1; ii > pow; ii--)
        {
            ret /= val;
        }
    }

    return ret;
}
