#include "effet.hpp"

#include <stdexcept>
#include <iostream>
#include <vector>

namespace effet
{
    glm::vec3 applyMatrix3(sil::Image &image, std::vector<std::vector<float>> matrix, int x, int y)
    {
        float red{0};
        float green{0};
        float blue{0};

        for (int i{-1}; i <= 1; i++)
        {
            for (int j{-1}; j <= 1; j++)
            {
                if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
                {
                    red += matrix[i + 1][j + 1] * image.pixel(x + i, y + j).r;
                    green += matrix[i + 1][j + 1] * image.pixel(x + i, y + j).g;
                    blue += matrix[i + 1][j + 1] * image.pixel(x + i, y + j).b;
                }
            }
        }

        return {red, green, blue};
    }

    sil::Image convolution(sil::Image image)
    {
        int choix;
        std::cout << "Quel effet voulez-vous appliquer ? : \n\n1 - Flou\n2 - Emboss\n3 - Outline\n4 - Sharpen\n"
                  << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;

        std::cout << "\033[2J\033[H";

        int taille{1};

        if (choix == 1)
        {
            std::cout << "Choisissez la taille de votre kernel : ";
            std::cin >> taille;

            std::cout << "\033[2J\033[H";
        }

        sil::Image new_image = image;
        std::vector<std::vector<float>> matrix;
        std::vector<std::vector<float>> matrix2;
        float valeur;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                float red{0};
                float green{0};
                float blue{0};
                int nb_voisins{0};

                switch (choix)
                {
                case 1:
                    for (int i{-taille}; i <= taille; i++)
                    {
                        for (int j{-taille}; j <= taille; j++)
                        {

                            if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
                            {
                                red += image.pixel(x + i, y + j).r;
                                green += image.pixel(x + i, y + j).g;
                                blue += image.pixel(x + i, y + j).b;

                                nb_voisins++;
                            }
                        }
                    }
                    red /= static_cast<float>(nb_voisins);
                    green /= static_cast<float>(nb_voisins);
                    blue /= static_cast<float>(nb_voisins);

                    new_image.pixel(x, y) = {red, green, blue};

                    break;
                case 2:

                    matrix = {{-2, -1, 0}, {-1, 1, 1}, {0, 1, 2}};
                    new_image.pixel(x, y) = applyMatrix3(image, matrix, x, y);
                    break;
                case 3:
                    matrix = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
                    matrix2 = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

                    glm::vec3 gx;
                    glm::vec3 gy;

                    gx = applyMatrix3(image, matrix, x, y);
                    gy = applyMatrix3(image, matrix2, x, y);

                    red = std::sqrt(gx.r * gx.r + gy.r * gy.r);
                    green = std::sqrt(gx.g * gx.g + gy.g * gy.g);
                    blue = std::sqrt(gx.b * gx.b + gy.b * gy.b);

                    valeur = red * 0.299 + green + 0.587 + blue * 0.114;

                    if (valeur >= 0.9f)
                    {
                        valeur = 0.f;
                    }
                    else
                    {
                        valeur = 1.f;
                    }

                    new_image.pixel(x, y) = {valeur, valeur, valeur};

                    break;
                case 4:

                    matrix = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
                    new_image.pixel(x, y) = applyMatrix3(image, matrix, x, y);

                    break;

                default:
                    break;
                }
            }
        }
        return new_image;
    }
}
