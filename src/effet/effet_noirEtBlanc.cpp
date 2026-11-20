#include "effet.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace effet
{
    sil::Image noirEtBlanc(sil::Image image)
    {

        for (glm::vec3 &color : image.pixels())
        {
            glm::vec3 finalColor;
            finalColor.r = color.r * 0.299 + color.g * 0.587 + color.b * 0.114;
            finalColor.g = color.r * 0.299 + color.g * 0.587 + color.b * 0.114;
            finalColor.b = color.r * 0.299 + color.g * 0.587 + color.b * 0.114;
            color = finalColor;
        };
        return image;
    }
}
