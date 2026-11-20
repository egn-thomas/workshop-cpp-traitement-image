#include "effet.hpp"

#include <stdexcept>
#include <complex>

namespace effet
{
    sil::Image mandelbrot(sil::Image image)
    {
        std::complex<float> z{3.f, 2.f};

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                std::complex<float> c{static_cast<float>(x) / image.width() * 3.f - 2.f, static_cast<float>(y) / image.height() * 2.f - 1.f};
                z = 0.f;
                int i{0};
                while (std::abs(z) < 2.f && i < 100)
                {
                    z = z * z + c;
                    i++;
                }

                if (i == 100)
                {
                    image.pixel(x, y) = {1.f, 1.f, 1.f};
                }
                else
                {
                    float t = i / 100.f;
                    image.pixel(x, y) = {t, t, t};
                }
            }
        }
        return image;
    }
}
