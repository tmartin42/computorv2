
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "AVar.hpp"
#include "Rational.hpp"

class Matrix : public AVar {
	public:
		Matrix();
		Matrix(std::vector< std::vector< Rational *> > matrix);
		Matrix(Matrix const & src);
		virtual ~Matrix();

		Matrix& operator=(Matrix const& rhs);
        
		TYPE			getType() const;

		std::vector< std::vector< Rational *> > getMat();
		void		setMat(std::vector< std::vector< Rational *> > matrix);

        virtual	void			display() const;

	private:
		std::vector< std::vector< Rational *> > _matrix;

};

#endif