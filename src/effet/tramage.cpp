#include "effet.hpp"

#include <utility>
#include <vector>
#include <iostream>

namespace effet
{
    float brightnessForDither(glm::vec3 const &color)
    {
        return color.r * 0.299f + color.g * 0.587f + color.b * 0.114f;
    }

    sil::Image tramage(sil::Image image)
    {
        const int bayer_n = 4;
        float bayer_matrix_4x4[][bayer_n] = {
            {-0.5, 0, -0.375, 0.125},
            {0.25, -0.25, 0.375, -0.125},
            {-0.3125, 0.1875, -0.4375, 0.0625},
            {0.4375, -0.0625, 0.3125, -0.1875},
        };

        for (int x = 0; x < image.width(); ++x)
        {
            for (int y = 0; y < image.height(); ++y)
            {
                float seuil = (bayer_matrix_4x4[y % bayer_n][x % bayer_n] + 0.5f);
                float output = brightnessForDither(image.pixel(x, y)) > seuil ? 1.f : 0.f;
                image.pixel(x, y) = {output, output, output};
            }
        }

        return image;
    }
}