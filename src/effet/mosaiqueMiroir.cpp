#include "effet.hpp"

#include <stdexcept>
#include <iostream>

namespace effet
{
    sil::Image mosaiqueMiroir(sil::Image image)
    {
        int taille;
        std::cout << "Veuillez entrer le nombre de tuiles sur un coté de la mosaique : " << std::endl;
        std::cin >> taille;

        sil::Image new_image{image.width() * taille, image.height() * taille};

        for (int x{0}; x < new_image.width(); x++)
        {
            for (int y{0}; y < new_image.height(); y++)
            {
                int localX{x % image.width()};
                int localY{y % image.height()};

                if ((x / image.width()) % 2 == 1)
                {
                    localX = image.width() - 1 - localX;
                }
                if ((y / image.height()) % 2 == 1)
                {
                    localY = image.height() - 1 - localY;
                }

                new_image.pixel(x, y) = image.pixel(localX, localY);
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
