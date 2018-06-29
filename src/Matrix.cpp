#include "Matrix.hpp"

Matrix::Matrix() {
}

Matrix::Matrix(std::vector< std::vector< Rational *> > matrix) {
	_matrix = matrix;
}

Matrix::Matrix(const Matrix& src) {
	*this = src;
}

Matrix::~Matrix() {
}

Matrix& Matrix::operator=(const Matrix& rhs) {
	(void)rhs;
	return (*this);
}


std::vector< std::vector< Rational *> > Matrix::getMat() {
    return _matrix;
}

void		Matrix::setMat(std::vector< std::vector< Rational *> > matrix) {
	_matrix = matrix;
}

TYPE			Matrix::getType() const {
    return      MATRIX;
}

void    Matrix::display() const {
	for (size_t i = 0; i < _matrix.size(); i++)  { 
		std::cout << "[ ";
		for (size_t j = 0; j < _matrix[i].size(); j++) {
			_matrix[i][j]->display();
			if (j < _matrix[i].size() - 1)
				std::cout << " , ";
		}
		std::cout << " ]" << std::endl;
	}
}


AVar    Matrix::scalMatToMat( AVar *rhs, int toDelete)  {
    std::vector< std::vector< Rational *> > rhsMat = dynamic_cast<Matrix *>(rhs)->getMat();
    if (_matrix[0].size() != rhsMat.size())
        throw std::exception();

    std::vector< std::vector< Rational *> > resM;
	for (size_t i = 0; i < _matrix.size(); i++)  {
        std::vector<Rational *> line;
    	for (size_t k = 0; k < rhsMat[0].size(); k++) {
            line.push_back(new Rational(0));
    	    for (size_t j = 0; j < rhsMat.size(); j++) {
                line[k] = line[k] + _matrix[i][j] * rhsMat[j][k];
            }
        }
        res.push_back(line);
    }  
    return Variable(res);
}

AVar    *Matrix::Add( AVar *rhs, int toDelete ) {
    if (rhs->getType() == RATIONAL) {
        std::vector< std::vector< Rational *> > resM = getMat();
		double val = dynamic_cast<Rational *>(rhs)->getVal();
        for (size_t i = 0; i < resM.size(); i++)  {
            for (size_t j = 0; j < resM[i].size(); j++) {
                resM[i][j] = resM[i][j]->add(rhs->getVal(), 0);
            }
        }
        Matrix *res = new Matrix(resM);
        del(rhs, toDelete);
        return res;
    } else if (rhs->getType() == MATRIX) {
        std::vector< std::vector< Rational *> > rhsMat = dynamic_cast<Matrix *>(rhs)->getMat();
		if (_matrix.size() != rhsMat.size() || _matrix[0].size() != rhsMat[0].size()) {
			std::cout << _matrix.size() << " " << rhsMat.size() << ", " << _matrix[0].size() << " " << rhsMat[0].size() <<std::endl;
			throw std::exception();
		}
        std::vector< std::vector< Rational *> > resM = getMat();

        for (size_t i = 0; i < resM.size(); i++)  {
            for (size_t j = 0; j < resM[i].size(); j++) {
                resM[i][j] = resM[i][j]->add(rhsMat[i][j]->getVal(), 0);
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