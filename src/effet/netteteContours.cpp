#include "effet.hpp"

#include <stdexcept>

namespace effet
{
    sil::Image netteteContours(sil::Image)
    {
        throw std::logic_error{"L'effet Netteté et contours n'est pas encore implémenté."};
    }
}
