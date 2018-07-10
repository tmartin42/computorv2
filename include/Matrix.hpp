
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
		AVar    	*scalMatToMat( AVar *rhs, int toDelete);
        void			display() const;
		AVar    *add( AVar *rhs, int toDelete = 0 );
		AVar    *add( double rhs, int toDelete = 0 ); 
		AVar    *mul( AVar *rhs, int toDelete = 0 );
		AVar    *mul( double rhs, int toDelete = 0 ); 



	private:
		std::vector< std::vector< Rational *> > _matrix;

};

#endif