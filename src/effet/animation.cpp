#include "effet.hpp"

#include <iostream>
#include <stdexcept>

namespace effet
{
    sil::Image animation(sil::Image image, int frame, int rayon)
    {

        int xo = frame;
        int yo = image.height() / 2;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x - xo, 2) + pow(y - yo, 2) <= pow(rayon, 2))
                {
                    image.pixel(x, y) = {1, 1, 1};
                }
            }
        }
        return image;
    }
}
