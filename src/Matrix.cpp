#include "Matrix.hpp"

Matrix::Matrix() {
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

TYPE			Matrix::getType() const {
    return      MATRIX;
}
void    Matrix::display() const {
    std::cout << "Todo";
}