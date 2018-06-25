
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "AVar.hpp"


class Matrix : public AVar {
	public:
		Matrix();
		Matrix(Matrix const & src);
		virtual ~Matrix();

		Matrix& operator=(Matrix const& rhs);
        
		TYPE			getType() const;

        virtual	void			display() const;

	private:

};

#endif