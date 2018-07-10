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
std::vector< std::vector<Variable> > Variable::getMat() const {
        std::cout << _matrix.size() << ", " << _matrix[0].size() << std::endl;
    return _matrix;
}

void    Variable::setMat(std::vector< std::vector<Variable> > matrix) {
    _matrix = matrix;
}

Variable    Variable::calcRatToMatrix(Variable const &rhs, CALC calc) const {

    std::vector< std::vector< Variable > > res = _matrix;

	for (size_t i = 0; i < res.size(); i++)  {
		for (size_t j = 0; j < res[i].size(); j++) {
            if (calc == ADD)
                res[i][j] = res[i][j] + rhs;
            else if (calc == MINUS)
                res[i][j] = res[i][j] - rhs;
            else if (calc == MUL)
                res[i][j] = res[i][j] * rhs;
            else if (calc == DIV)
                res[i][j] = res[i][j] / rhs;
            else if (calc == MOD)
                res[i][j] = res[i][j] % rhs;
        }
    }

    return Variable(res);
}
Variable    Variable::calcMatToMat(std::vector< std::vector<Variable> > rhsMat, CALC calc) const {

    if (_matrix.size() != rhsMat.size() || _matrix[0].size() != rhsMat[0].size()) {
        std::cout << _matrix.size() << " " << rhsMat.size() << ", " << _matrix[0].size() << " " << rhsMat[0].size() <<std::endl;
        throw std::exception();
    }

    std::vector< std::vector< Variable > > res = _matrix;

	for (size_t i = 0; i < res.size(); i++)  {
		for (size_t j = 0; j < res[i].size(); j++) {
            if (calc == ADD)
                res[i][j] = res[i][j] + rhsMat[i][j];
            else if (calc == MINUS)
                res[i][j] = res[i][j] - rhsMat[i][j];
            else if (calc == MUL)
                res[i][j] = res[i][j] * rhsMat[i][j];
            else if (calc == DIV)
                res[i][j] = res[i][j] / rhsMat[i][j];
            else if (calc == MOD)
                res[i][j] = res[i][j] % rhsMat[i][j];
        }
    }

    return Variable(res);
}

Variable    Variable::scalMatToMat(std::vector< std::vector<Variable> > rhsMat)  {
    if (_matrix[0].size() != rhsMat.size())
        throw std::exception();

    std::vector< std::vector< Variable > > res;
	for (size_t i = 0; i < _matrix.size(); i++)  {
        std::vector<Variable> line;
    	for (size_t k = 0; k < rhsMat[0].size(); k++) {
            line.push_back(Variable(0));
    	    for (size_t j = 0; j < rhsMat.size(); j++) {
                line[k] = line[k] + _matrix[i][j] * rhsMat[j][k];
            }
        }
        res.push_back(line);
    }  
    return Variable(res);
}

Variable   Variable::poww(int poww) {
    if (getType() == RATIONAL) {
        double mul = _val;
        double ret = _val;
        for (int k = 0; k < poww - 1; k++) {
            ret = ret * mul;
        }
        return Variable(ret);
    } else if (getType() == MATRIX) {
        std::vector< std::vector<Variable> > ret = _matrix;
        for (size_t i = 0; i < ret.size(); i++)  {
            for (size_t j = 0; j < ret[i].size(); j++) {
                Variable mul = ret[i][j];
                for (int k = 0; k < poww - 1; k++) {
                    ret[i][j] = ret[i][j] * mul;
                }
            }
        }
        return Variable(ret);
    }
    throw std::exception();
    return Variable(-1);
}

Variable   Variable::operator+( Variable  const &rhs )  {


    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " + " << rhs.getRat() << std::endl;
        return Variable(_val + rhs.getRat());
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        if (getType() == MATRIX)
            return calcRatToMatrix(rhs, ADD);
        return rhs.calcRatToMatrix(*this, ADD);
    } else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), ADD);
    }

    return *this;
}

Variable    Variable::operator-( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " - " << rhs.getRat() << std::endl;
        return Variable(_val - rhs.getRat());
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        if (getType() == MATRIX)
            return calcRatToMatrix(rhs, MINUS);
        return rhs.calcRatToMatrix(*this, MINUS);
    } else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), MINUS);
    }
    return *this;
}

Variable    Variable::operator*( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " * " << rhs.getRat() << std::endl;
        return Variable(_val * rhs.getRat());
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        if (getType() == MATRIX)
            return calcRatToMatrix(rhs, MUL);
        return rhs.calcRatToMatrix(*this, MUL);
    } else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), MUL);
    }
    return *this;
}
Variable    Variable::operator/( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " / " << rhs.getRat() << std::endl;
        return Variable(_val / rhs.getRat());
   
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        if (getType() == MATRIX)
            return calcRatToMatrix(rhs, DIV);
        return rhs.calcRatToMatrix(*this, DIV);
    } else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), DIV);
    }
    return *this;
}

Variable   Variable::operator%( Variable const &rhs )  {

    if (rhs.getType() == RATIONAL && getType() == RATIONAL) {
        std::cout << _val << " % " << rhs.getRat() << std::endl;
        return Variable(fmod(_val, rhs.getRat()));
    } else if ((rhs.getType() == RATIONAL && getType() == MATRIX) || (rhs.getType() == MATRIX && getType() == RATIONAL)) {
        if (getType() == MATRIX)
            return calcRatToMatrix(rhs, MOD);
        return rhs.calcRatToMatrix(*this, MOD);
    } else if (rhs.getType() == MATRIX && getType() == MATRIX) {
        return calcMatToMat(rhs.getMat(), MOD);
    }

    return *this;
}

/*
Variable const   *Variable::operator**( Variable  &rhs ) const {

    throw std::exception;

    return this;
}
*/