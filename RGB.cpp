//
// Created by arxa on 26/3/2017.
//

#include "RGB.h"

namespace arxa
{
    RGB::RGB(double r1, double g1, double b1) : r(r1), g(g1), b(b1)
    {}

    RGB operator-(const RGB &first, const RGB &second)
    {
        return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
    }
}