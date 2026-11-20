#include "effet.hpp"

#include <stdexcept>
#include <iostream>

namespace effet
{
    sil::Image cercle(sil::Image image)
    {
        int rayon;
        int epaisseur;

        std::cout << "Veuillez entrer la taille du rayon du cerlce souhaitée (< à 250) : " << std::endl;
        std::cin >> rayon;
        std::cout << "Veuillez entrer l'épaisseur du tracé du cercle souhaitée (< à 50) : " << std::endl;
        std::cin >> epaisseur;

        int xo = image.width() / 2;
        int yo = image.height() / 2;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x - xo, 2) + pow(y - yo, 2) <= pow(rayon, 2) && pow(x - xo, 2) + pow(y - yo, 2) >= pow(rayon - epaisseur, 2))
                {
                    image.pixel(x, y) = {1, 1, 1};
                }
            }
        }
        return image;
    }
}
