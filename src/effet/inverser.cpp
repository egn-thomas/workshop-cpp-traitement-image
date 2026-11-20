#include "effet.hpp"

namespace effet
{
    sil::Image inverser(sil::Image image)
    {
        for (glm::vec3 &color : image.pixels())
        {
            color.r = 1 - color.r;
            color.g = 1 - color.g;
            color.b = 1 - color.b;
        };
        return image;
    }

}
