#include "effet.hpp"
#include <random>

namespace effet
{
    sil::Image bruit(sil::Image image)
    {
        for (glm::vec3 &color : image.pixels())
        {
            if (rand() % 100 > 70)
            {
                color.r = (rand() % 100) / 100.f;
                color.g = (rand() % 100) / 100.f;
                color.b = (rand() % 100) / 100.f;
            }
        };
        return image;
    }

}
