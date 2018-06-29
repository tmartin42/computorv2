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

AVar    *Rational::Add( AVar *rhs, int toDelete ) {
    if (rhs.getType() == RATIONAL) {
        std::cout << _val << " + " << rhs.getRat() << std::endl;
        Rational *res = new Rational(_val + rhs->getVal());
        del(rhs, toDelete);
        return res;
    } else if (rhs.getType() == MATRIX) {
        std::vector< std::vector< Rational > > resM = dynamic_cast<Matrix *>(rhs)->getMatrix();
        for (size_t i = 0; i < resM.size(); i++)  {
            for (size_t j = 0; j < resM[i].size(); j++) {
                resM[i][j] = resM[i][j].add(_val, 0);
            }
        }
        Matrix *res = new Matrix(resM);
        del(rhs, toDelete);
        return res;
    }
    del(rhs, toDelete);
    return new Rational(-1);
    /*else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), ADD);
    }*/
} 
/*

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
}*/
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