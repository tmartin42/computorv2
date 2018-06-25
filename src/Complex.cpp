#include "Complex.hpp"

Complex::Complex() {
}

Complex::Complex(const Complex& src) {
	*this = src;
}

Complex::~Complex() {
}

Complex& Complex::operator=(const Complex& rhs) {
	(void)rhs;
	return (*this);
}

TYPE			Complex::getType() const {
    return      COMPLEX;
}
void    Complex::display() const {
    std::cout << "Todo";
}