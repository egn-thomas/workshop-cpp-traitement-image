#include "effet.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace effet
{
    sil::Image choisirImage(std::vector<std::string> imagesDisponibles)
    {
        std::cout << "Choisissez une image à modifier : \n"
                  << std::endl;
        for (size_t i = 0; i < imagesDisponibles.size(); i++)
        {
            std::cout << i + 1 << " - " << imagesDisponibles[i] << std::endl;
        }
        size_t choix;

        std::cout << "\nVotre choix : ";

        std::cin >> choix;

        std::cout << "\033[2J\033[H";

        std::string chemin = "images/" + imagesDisponibles[choix - 1];
        return sil::Image{chemin};
    }
}
