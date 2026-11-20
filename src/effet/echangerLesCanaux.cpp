#include "effet.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace effet
{
    sil::Image echangerLesCanaux(sil::Image image)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                std::swap(image.pixel(x, y).r, image.pixel(x, y).b);
            }
        }
        return image;
    }

}
