#include "effet.hpp"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

namespace effet
{
    float brightness(glm::vec3 const &color)
    {
        return 0.299f * color.r + 0.587f * color.g + 0.114f * color.b;
    }

    sil::Image triTousLesPixels(sil::Image image)
    {
        std::vector<glm::vec3> pixels = image.pixels();
        std::sort(pixels.begin(), pixels.end(), [](glm::vec3 const &a, glm::vec3 const &b)
                  { return brightness(a) < brightness(b); });

        sil::Image new_image{image.width(), image.height()};
        new_image.pixels() = std::move(pixels);
        return new_image;
    }

    sil::Image triParLigne(sil::Image image)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            std::vector<glm::vec3> row;
            for (int x = 0; x < image.width(); ++x)
            {
                row.push_back(image.pixel(x, y));
            }

            std::sort(row.begin(), row.end(), [](glm::vec3 const &a, glm::vec3 const &b)
                      { return brightness(a) < brightness(b); });

            for (int x = 0; x < image.width(); ++x)
            {
                image.pixel(x, y) = row[x];
            }
        }
        return image;
    }

    sil::Image triPixels(sil::Image image)
    {
        int choix;
        std::cout << "Choisissez le type de tri :\n1 - Tri de tous les pixels\n2 - Tri par ligne"
                  << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            return triTousLesPixels(image);
        case 2:
            return triParLigne(image);
        default:
            std::cerr << "Choix invalide." << std::endl;
            return image;
        }
    }
}
