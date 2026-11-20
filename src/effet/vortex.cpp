#include "effet.hpp"

#include <stdexcept>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <iostream>

namespace effet
{
    glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
    {
        return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
    }

    sil::Image vortex(sil::Image image)
    {
        int force;
        std::cout << "Veuillez entrer la force de l'effet ( entre 1 et 100 ) : ";
        std::cin >> force;

        std::cout << "\033[2J\033[H";

        sil::Image new_image = image;

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                glm::vec2 point = {x, y};
                glm::vec2 center = {image.width() / 2, image.height() / 2};

                float angle = (glm::distance(point, center) / 100.f) * force;

                glm::vec2 point_rotated = rotated(point, center, angle);

                if (0 < point_rotated.x && point_rotated.x <= image.width() && 0 < point_rotated.y && point_rotated.y <= image.height())
                {
                    image.pixel(point.x, point.y) = new_image.pixel(point_rotated.x, point_rotated.y);
                }
                else
                {
                    image.pixel(x, y) = {0, 0, 0};
                }
            }
        }
        return image;
    }
}
