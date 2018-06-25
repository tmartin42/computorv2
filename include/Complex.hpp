
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "AVar.hpp"


class Complex : public AVar {
	public:
		Complex();
		Complex(Complex const & src);
		virtual ~Complex();

		Complex& operator=(Complex const& rhs);
        
		TYPE			getType() const;

        virtual	void			display() const;

	private:

};

#endif