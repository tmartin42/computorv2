#include "AVar.hpp"

void        AVar::del(AVar *rhs, int toDelete)
{
    if (toDelete != 1 && toDelete != 0)
        delete rhs;
    if (toDelete != 2 && toDelete != 0)
        delete this;
}

double       AVar::getVal() const {
    return -1;
}