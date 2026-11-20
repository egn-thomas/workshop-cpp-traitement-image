#include "effet.hpp"

namespace effet
{
    sil::Image miroir(sil::Image image)
    {
        sil::Image new_image = image;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                new_image.pixel(image.width() - 1 - x, y) = image.pixel(x, y);
            }
        }
        return new_image;
    }

}
