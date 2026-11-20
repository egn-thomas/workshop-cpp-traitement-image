#include "effet.hpp"
#include <algorithm>

namespace effet
{
    sil::Image rgbSplit(sil::Image image)
    {
        sil::Image new_image{image.width(), image.height()};

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                int voisinGauche = std::max(0, x - 10);
                int voisinDroite = std::min(image.width() - 1, x + 10);

                new_image.pixel(x, y).r = image.pixel(voisinGauche, y).r;
                new_image.pixel(x, y).g = image.pixel(x, y).g;
                new_image.pixel(x, y).b = image.pixel(voisinDroite, y).b;
            }
        }
        return new_image;
    }
}
