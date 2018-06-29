
#ifndef AVAR_HPP
#define AVAR_HPP

#include <iostream>
#include <exception>
#include <math.h>
#include <vector>

enum	TYPE { NOTYPE, RATIONAL, INDE, COMPLEX, MATRIX, POLY };

class AVar {
	public:
		virtual ~AVar() {};
		void    del(AVar *rhs, int toDelete);

		virtual TYPE			getType() const = 0;
		virtual	void			display() const = 0;
		virtual double			getVal() const;
	private:

};



#endif