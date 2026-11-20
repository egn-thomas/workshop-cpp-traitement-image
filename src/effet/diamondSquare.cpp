#include "effet.hpp"

#include <stdexcept>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <random>
#include <vector>

namespace effet
{
    // Calcule le centre de chaque carré à partir de ses quatre coins.
    void square_step(sil::Image &image, size_t step, float amplitude)
    {
        size_t half = step / 2;
        size_t width = image.width();
        size_t height = image.height();

        // Chaque carré de côté `step` reçoit une nouvelle valeur en son centre.
        for (size_t x = 0; x + step < width; x += step)
        {
            for (size_t y = 0; y + step < height; y += step)
            {

                float somme = 0.f;
                size_t nombreVoisins = 4;

                // Moyenne des quatre coins du carré.
                somme += image.pixel(x, y).r;
                somme += image.pixel(x + step, y).r;
                somme += image.pixel(x, y + step).r;
                somme += image.pixel(x + step, y + step).r;

                float valeur = somme / nombreVoisins;

                // Décale aléatoirement la moyenne pour créer du relief.
                float variation = (rand() % 100 / 100.f) * amplitude;
                int signe = (rand() % 2);

                if (signe == 1)
                {
                    valeur += variation;
                }
                else
                {
                    valeur -= variation;
                }

                image.pixel(x + half, y + half) = {valeur, valeur, valeur};
            }
        }
    }

    // Calcule les points en losange à partir de leurs voisins cardinaux.
    void diamond_step(sil::Image &image, size_t step, float amplitude)
    {
        size_t half = step / 2;
        size_t width = image.width();
        size_t height = image.height();

        // Les lignes sont parcourues en quinconce pour viser les milieux
        // des côtés des carrés calculés pendant l'étape square.
        for (size_t y = 0; y < height; y += half)
        {
            size_t debutX = ((y / half) % 2 == 0) ? half : 0;

            for (size_t x = debutX; x < width; x += step)
            {
                float somme = 0.f;
                size_t nombreVoisins = 0;

                // Aux bords, seuls les voisins qui appartiennent à l'image
                // contribuent à la moyenne.
                if (y >= half)
                {
                    somme += image.pixel(x, y - half).r;
                    nombreVoisins++;
                }
                if (x + half < width)
                {
                    somme += image.pixel(x + half, y).r;
                    nombreVoisins++;
                }
                if (y + half < height)
                {
                    somme += image.pixel(x, y + half).r;
                    nombreVoisins++;
                }
                if (x >= half)
                {
                    somme += image.pixel(x - half, y).r;
                    nombreVoisins++;
                }

                float valeur = somme / nombreVoisins;

                // La même perturbation aléatoire évite une interpolation trop lisse.
                float variation = (rand() % 100 / 100.f) * amplitude;
                int signe = (rand() % 2);

                if (signe == 1)
                {
                    valeur += variation;
                }
                else
                {
                    valeur -= variation;
                }

                image.pixel(x, y) = {valeur, valeur, valeur};
            }
        }
    }

    // Répète les deux étapes en divisant la taille des carrés par deux.
    // L'amplitude du bruit diminue à chaque niveau selon le paramètre H.
    void process_image(sil::Image &image, float amplitude, float H)
    {
        for (size_t step = image.width() - 1; step > 1; step /= 2)
        {
            square_step(image, step, amplitude);
            diamond_step(image, step, amplitude);
            amplitude *= std::pow(2.f, -H);
        }
    }

    sil::Image diamondSquare(sil::Image image)
    {
        // Amplitude initiale des variations et exposant de décroissance.
        float amplitude = 0.5f;
        float H = 1.0f;

        // Initialise les quatre coins avec des hauteurs aléatoires identiques
        // sur les trois canaux, afin de produire une carte en niveaux de gris.
        float x = rand() % 100 / 100.f;
        glm::vec3 p1{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p2{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p3{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p4{x, x, x};

        // Les coins sont les valeurs de départ de l'algorithme.
        image.pixel(0.f, 0.f) = p1;
        image.pixel(image.width() - 1, 0.f) = p2;
        image.pixel(0.f, image.height() - 1) = p3;
        image.pixel(image.width() - 1, image.height() - 1) = p4;

        process_image(image, amplitude, H);

        // Cette fonction retourne une copie normalisée, mais son résultat
        // n'est pas réaffecté à `image` ici.
        effet::normalisationHistogramme(image);

        return image;
    }
}
