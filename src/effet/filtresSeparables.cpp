#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image filtresSeparables(sil::Image)
    {
        throw std::logic_error{"L'effet Filtres séparables n'est pas encore implémenté."};
    }
}
