
#ifndef AVAR_HPP
#define AVAR_HPP

#include <iostream>
#include <exception>
#include <math.h>
enum	TYPE { NOTYPE, RATIONAL, INDE, COMPLEX, MATRIX, POLY };

class AVar {
	public:
		virtual ~AVar() {};

		virtual TYPE			getType() const = 0;
		virtual	void			display() const = 0;
	private:

};



#endif