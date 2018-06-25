#include "Poly.hpp"

Poly::Poly() {
}

Poly::Poly(const Poly& src) {
	*this = src;
}

Poly::~Poly() {
}

Poly& Poly::operator=(const Poly& rhs) {
	(void)rhs;
	return (*this);
}

TYPE			Poly::getType() const {
    return      POLY;
}
void    Poly::display() const {
    std::cout << "Todo";
}