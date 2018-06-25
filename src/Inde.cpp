#include "Inde.hpp"

Inde::Inde() {
}

Inde::Inde(const Inde& src) {
	*this = src;
}

Inde::~Inde() {
}

Inde& Inde::operator=(const Inde& rhs) {
	(void)rhs;
	return (*this);
}

TYPE			Inde::getType() const {
    return      INDE;
}
void    Inde::display() const {
    std::cout << "Todo";
}