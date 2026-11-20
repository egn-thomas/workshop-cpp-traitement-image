#include "effet.hpp"

namespace effet
{
    sil::Image neGarderQueLeVert(sil::Image image)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                image.pixel(x, y).r = 0.f;
                image.pixel(x, y).b = 0.f;
            }
        }
        return image;
    }

}
