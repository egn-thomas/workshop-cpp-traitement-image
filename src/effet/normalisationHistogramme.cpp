#include "effet.hpp"

#include <stdexcept>
#include <vector>
#include <algorithm>

namespace effet
{
    sil::Image normalisationHistogramme(sil::Image image)
    {
        float minVal = 1.f;
        float maxVal = 0.f;

        // Parcours des pixels pour trouver min et max
        for (glm::vec3 &p : image.pixels())
        {
            minVal = std::min({minVal, p.r, p.g, p.b});
            maxVal = std::max({maxVal, p.r, p.g, p.b});
        }

        // étirage de la plage de valeurs
        if (maxVal - minVal != 0)
        {
            for (glm::vec3 &p : image.pixels())
            {
                p = (p - minVal) / (maxVal - minVal);
            }
        }
        return image;
    }
}
