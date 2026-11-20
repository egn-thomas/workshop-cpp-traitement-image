#include "effet.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

namespace effet
{
    sil::Image glitch(sil::Image image)
    {
        int quantite;
        std::cout << "Veuillez entrer la force de l'effet (entre 1 et 10) : ";
        std::cin >> quantite;
        std::cout << "\033[2J\033[H";

        for (int i = 0; i < quantite * 15; i++)
        {
            const int largeur = std::min((rand() % 20) + 30, image.width());
            const int hauteur = std::min((rand() % 5) + 5, image.height());
            const int x1 = rand() % (image.width() - largeur + 1);
            const int y1 = rand() % (image.height() - hauteur + 1);
            const int x12 = rand() % (image.width() - largeur + 1);
            const int y12 = rand() % (image.height() - hauteur + 1);

            for (int dx = 0; dx < largeur; dx++)
            {
                for (int dy = 0; dy < hauteur; dy++)
                {
                    image.pixel(x1 + dx, y1 + dy) = image.pixel(x12 + dx, y12 + dy);
                }
            }
        }

        return image;
    }
}
