#include "effet.hpp"
#include <cmath>
#include <iostream>

namespace effet
{
    sil::Image disque(sil::Image image)
    {
        int choix;
        std::cout << "Veuillez entrer la taille du rayon du disque souhaitée (< à 250) : ";
        std::cin >> choix;
        std::cout << "\033[2J\033[H";

        int xo = image.width() / 2;
        int yo = image.height() / 2;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x - xo, 2) + pow(y - yo, 2) <= pow(choix, 2))
                {
                    image.pixel(x, y) = {1, 1, 1};
                }
            }
        }
        return image;
    }

}
