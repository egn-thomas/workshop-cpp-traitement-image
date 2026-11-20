#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image differencesGaussiennes(sil::Image)
    {
        throw std::logic_error{"L'effet Différences de gaussiennes n'est pas encore implémenté."};
    }
}
