#include "Variable.hpp"

Variable::Variable() {
    _val = 0;
    _type = NOTYPE;
    _matrix = std::vector< std::vector<Variable> >(0);
}

Variable::Variable(double val) {
    _val = val;
    _matrix = std::vector< std::vector<Variable> >(0);
    _type = RATIONAL;
}

Variable::Variable(std::vector< std::vector<Variable> > matrix) {
    _val = 0;
    _matrix = matrix;
    _type = MATRIX;
}

Variable::Variable(const Variable& src) {
	*this = src;
}

Variable::~Variable() {
}

Variable& Variable::operator=(const Variable& rhs) {
	_val = rhs._val;
	_type = rhs._type;
    _matrix = rhs._matrix;
	return (*this);
}

TYPE			Variable::getType() const {
    return      _type;
}

void    Variable::display() const {
    if (getType() == RATIONAL)
        std::cout << _val;
    else if (getType() == MATRIX) {
        for (size_t i = 0; i < _matrix.size(); i++)  { 
            std::cout << "[ ";
            for (size_t j = 0; j < _matrix[i].size(); j++) {

                _matrix[i][j].display();
                if (j < _matrix[i].size() - 1)
                    std::cout << " , ";
            }
            std::cout << " ]" << std::endl;
        }
    }
}

double  Variable::getRat() const {
    return _val;
}

void    Variable::setRat(double newVal) {
    _val = newVal;
}

Variable    Variable::addToMatrix(Variable const &rhs) const {

    std::vector< std::vector< Variable > > res = _matrix;

	for (size_t i = 0; i < res.size(); i++)  {
		for (size_t j = 0; j < res[i].size(); j++) {
            res[i][j] = res[i][j] + rhs;
        }
    }

    return Variable(res);
}

Variable   Variable::operator+( Variable  const &rhs )  {


    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " + " << rhs.getRat() << std::endl;
        return Variable(_val + rhs.getRat());
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        std::cout << "in";
        if (getType() == MATRIX) {
            return addToMatrix(rhs);
        } else {
            return rhs.addToMatrix(*this);
        }
        
    }

    return *this;
}

Variable    Variable::operator-( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " - " << rhs.getRat() << std::endl;
        return Variable(_val - rhs.getRat());
    }
    return *this;
}

Variable    Variable::operator*( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " * " << rhs.getRat() << std::endl;
        return Variable(_val * rhs.getRat());
    }
    return *this;
}
Variable    Variable::operator/( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " / " << rhs.getRat() << std::endl;
        return Variable(_val / rhs.getRat());
    }
    return *this;
}

Variable   Variable::operator%( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL)
        std::cout << _val << " % " << rhs.getRat() << std::endl;
        return Variable(fmod(_val, rhs.getRat()));

    return *this;
}
/*
Variable const   *Variable::operator**( Variable  &rhs ) const {

    throw std::exception;

    return this;
}
*/