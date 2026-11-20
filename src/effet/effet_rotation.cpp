#include "effet.hpp"

namespace effet
{
    sil::Image rotation(sil::Image image)
    {
        int new_width = image.height();
        int new_height = image.width();

        sil::Image new_image{new_width, new_height};

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                // new_image.pixel(y, image.height() - 1 - x) = image.pixel(x, y); /*sens horaire*/
                new_image.pixel(image.height() - 1 - y, x) = image.pixel(x, y); /*sens anti-horaire*/
            }
        }
        return new_image;
    }
}
