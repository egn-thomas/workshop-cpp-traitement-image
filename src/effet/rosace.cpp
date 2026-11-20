#include "effet.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>

namespace effet
{
    sil::Image rosace(sil::Image image)
    {
        int rayon;
        int epaisseur;

        std::cout << "Veuillez entrer la taille du rayon des cerlce souhaitée (< à 250) : " << std::endl;
        std::cin >> rayon;
        std::cout << "Veuillez entrer l'épaisseur du tracé des cercle souhaitée (< à 50) : " << std::endl;
        std::cin >> epaisseur;

        int xo = image.width() / 2;
        int yo = image.height() / 2;

        float x1 = xo + ((rayon + (rayon - epaisseur)) / 2.f);
        float y1 = yo;

        float x2 = xo + (1.f / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);
        float y2 = yo + (sqrt(3.f) / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);

        float x3 = xo - (1.f / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);
        float y3 = yo + (sqrt(3.f) / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);

        float x4 = xo - ((rayon + (rayon - epaisseur)) / 2.f);
        float y4 = yo;

        float x5 = xo + (1.f / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);
        float y5 = yo - (sqrt(3.f) / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);

        float x6 = xo - (1.f / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);
        float y6 = yo - (sqrt(3.f) / 2.f) * ((rayon + (rayon - epaisseur)) / 2.f);

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x - xo, 2) + pow(y - yo, 2) <= pow(rayon, 2) && pow(x - xo, 2) + pow(y - yo, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x1, 2) + pow(y - y1, 2) <= pow(rayon, 2) && pow(x - x1, 2) + pow(y - y1, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x2, 2) + pow(y - y2, 2) <= pow(rayon, 2) && pow(x - x2, 2) + pow(y - y2, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x3, 2) + pow(y - y3, 2) <= pow(rayon, 2) && pow(x - x3, 2) + pow(y - y3, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x4, 2) + pow(y - y4, 2) <= pow(rayon, 2) && pow(x - x4, 2) + pow(y - y4, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x5, 2) + pow(y - y5, 2) <= pow(rayon, 2) && pow(x - x5, 2) + pow(y - y5, 2) >= pow(rayon - epaisseur, 2) ||
                    pow(x - x6, 2) + pow(y - y6, 2) <= pow(rayon, 2) && pow(x - x6, 2) + pow(y - y6, 2) >= pow(rayon - epaisseur, 2))
                {
                    image.pixel(x, y) = {1, 1, 1};
                }
            }
        }
        return image;
    }
}
