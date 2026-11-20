#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image kuwahara(sil::Image)
    {
        throw std::logic_error{"L'effet Kuwahara n'est pas encore implémenté."};
    }
}
