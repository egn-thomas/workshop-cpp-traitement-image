#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image colorerHeightMap(sil::Image image)
    {
        glm::vec3 vert_tres_fonce{0.02f, 0.15f, 0.05f};
        glm::vec3 vert_fonce{0.05f, 0.35f, 0.12f};
        glm::vec3 vert_moyen{0.20f, 0.60f, 0.20f};
        glm::vec3 vert_clair{0.60f, 0.85f, 0.40f};

        glm::vec3 bleu_tres_fonce{0.01f, 0.05f, 0.25f};
        glm::vec3 bleu_fonce{0.05f, 0.30f, 0.65f};
        glm::vec3 bleu_moyen{0.20f, 0.60f, 0.90f};
        glm::vec3 bleu_clair{0.70f, 0.90f, 1.00f};

        for (glm::vec3 &color : image.pixels())
        {

            if (color.r > 0.8)
            {
                color = vert_tres_fonce;
            }
            else if (color.r > 0.7)
            {
                color = vert_fonce;
            }
            else if (color.r > 0.6)
            {
                color = vert_moyen;
            }
            else if (color.r > 0.5)
            {
                color = vert_clair;
            }
            else if (color.r > 0.4)
            {
                color = bleu_clair;
            }
            else if (color.r > 0.3)
            {
                color = bleu_moyen;
            }
            else if (color.r > 0.2)
            {
                color = bleu_fonce;
            }
            else
            {
                color = bleu_tres_fonce;
            }
        }
        return image;
    }
}
