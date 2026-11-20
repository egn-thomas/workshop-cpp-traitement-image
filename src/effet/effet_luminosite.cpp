#include "effet.hpp"
#include <random>
#include <cmath>
#include <iostream>

namespace effet
{
    sil::Image luminosite(sil::Image image)
    {
        std::cout << "Choisissez l'operation\n1 - Augmenter la luminosité\n2 - Baisser la luminosité" << std::endl;

        int choix;

        std::cin >> choix;

        for (glm::vec3 &color : image.pixels())
        {
            if (choix == 2)
            { // Diminuer la luminosité
                color.r = pow(color.r, 2);
                color.g = pow(color.g, 2);
                color.b = pow(color.b, 2);
            }
            else if (choix == 1)
            { // Augmenter la luminosité
                color.r = pow(color.r, 1 / 2.f);
                color.g = pow(color.g, 1 / 2.f);
                color.b = pow(color.b, 1 / 2.f);
            }
            else
            {
                std::cout << "[ERROR] Choix invalide" << std::endl;
            }
        };
        return image;
    }

}
