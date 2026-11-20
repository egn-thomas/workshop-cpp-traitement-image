#include "effet.hpp"

#include <stdexcept>
#include <iostream>

namespace effet
{
    sil::Image mosaique(sil::Image image)
    {
        int taille;
        std::cout << "Veuillez entrer le nombre de tuiles sur un coté de la mosaique : " << std::endl;
        std::cin >> taille;

        sil::Image new_image{image.width() * taille, image.height() * taille};

        for (int x{0}; x < new_image.width(); x++)
        {
            for (int y{0}; y < new_image.height(); y++)
            {
                new_image.pixel(x, y) = image.pixel(x % image.width(), y % image.height());
            }
        }

        sil::Image new_image_reduced{image.width(), image.height()};

        for (int x{0}; x < new_image_reduced.width(); x++)
        {
            for (int y{0}; y < new_image_reduced.height(); y++)
            {
                new_image_reduced.pixel(x, y) = new_image.pixel(x * taille, y * taille);
            }
        }

        return new_image_reduced;
    }
}
