#include "effet.hpp"

#include <stdexcept>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <random>
#include <vector>

namespace effet
{
    void square_step(sil::Image &image, size_t step, float amplitude)
    {
        size_t half = step / 2;
        size_t width = image.width();
        size_t height = image.height();

        for (size_t x = 0; x + step < width; x += step)
        {
            for (size_t y = 0; y + step < height; y += step)
            {

                float somme = 0.f;
                size_t nombreVoisins = 4;

                somme += image.pixel(x, y).r;
                somme += image.pixel(x + step, y).r;
                somme += image.pixel(x, y + step).r;
                somme += image.pixel(x + step, y + step).r;

                float valeur = somme / nombreVoisins;

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

    void diamond_step(sil::Image &image, size_t step, float amplitude)
    {
        size_t half = step / 2;
        size_t width = image.width();
        size_t height = image.height();

        for (size_t y = 0; y < height; y += half)
        {
            size_t debutX = ((y / half) % 2 == 0) ? half : 0;

            for (size_t x = debutX; x < width; x += step)
            {
                float somme = 0.f;
                size_t nombreVoisins = 0;

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
        float amplitude = 0.5f;
        float H = 1.0f;

        float x = rand() % 100 / 100.f;
        glm::vec3 p1{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p2{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p3{x, x, x};

        x = rand() % 100 / 100.f;
        glm::vec3 p4{x, x, x};

        image.pixel(0.f, 0.f) = p1;
        image.pixel(image.width() - 1, 0.f) = p2;
        image.pixel(0.f, image.height() - 1) = p3;
        image.pixel(image.width() - 1, image.height() - 1) = p4;

        process_image(image, amplitude, H);

        effet::normalisationHistogramme(image);

        return image;
    }
}
