#include "effet.hpp"

namespace effet
{
    sil::Image degradeLab(sil::Image image)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                glm::vec3 colora = {1.f, 0.f, 0.f};
                glm::vec3 colorb = {0.f, 1.f, 0.f};

                glm::vec3 newcolor = glm::mix(colora, colorb, x / static_cast<float>(image.width()));

                image.pixel(x, y) = newcolor;
            }
        }
        return image;
    }

}