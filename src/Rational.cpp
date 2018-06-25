#include "Rational.hpp"

Rational::Rational() {
    _val = 0;
}

Rational::Rational(double val) {
    _val = val;
}

Rational::Rational(const Rational& src) {
	*this = src;
}

Rational::~Rational() {
}

Rational& Rational::operator=(const Rational& rhs) {
	_val = rhs._val;
	return (*this);
}

TYPE			Rational::getType() const {
    return      RATIONAL;
}

void    Rational::display() const {
    std::cout << _val << std::endl;
}

double  Rational::getVal() const {
    return _val;
}

void    Rational::setVal(double newVal) {
    _val = newVal;
}

AVar    &Rational::operator+( AVar  &rhs )  {

    if (rhs.getType() == RATIONAL) {
         static Rational lol = Rational(_val + dynamic_cast<Rational &>(rhs).getVal());
        return lol;
    }

    return *this;
}

AVar    &Rational::operator-( AVar  &rhs )  {

    if (rhs.getType() == RATIONAL) {
         static Rational lol = Rational(_val - dynamic_cast<Rational &>(rhs).getVal());
        return lol;
    }
    return *this;
}
/*
AVar    &Rational::operator*( AVar  &rhs )  {

    if (rhs.getType() == RATIONAL)
        return new Rational(_val * dynamic_cast<Rational &>(rhs).getVal());

    return this;
}

AVar   &Rational::operator/( AVar  &rhs )  {

    if (rhs.getType() == RATIONAL)
        return new Rational(_val / dynamic_cast<Rational &>(rhs).getVal());

    return this;
}

AVar    &Rational::operator%( AVar  &rhs )  {

    if (rhs.getType() == RATIONAL)
        return new Rational(fmod(_val, dynamic_cast<Rational &>(rhs).getVal()));

    return this;
}*/
/*
AVar const   *Rational::operator**( AVar  &rhs ) const {

    throw std::exception;

    return this;
}
*/