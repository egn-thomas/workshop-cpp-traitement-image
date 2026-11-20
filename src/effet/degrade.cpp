#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image degrade(sil::Image image)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                image.pixel(x, y).r = x / static_cast<float>(image.width());
                image.pixel(x, y).g = x / static_cast<float>(image.width());
                image.pixel(x, y).b = x / static_cast<float>(image.width());
            }
        }
        return image;
    }
}
