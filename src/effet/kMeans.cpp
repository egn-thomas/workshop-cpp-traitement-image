#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image kMeans(sil::Image)
    {
        throw std::logic_error{"L'effet K-means n'est pas encore implémenté."};
    }
}
