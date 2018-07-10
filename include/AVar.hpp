
#ifndef AVAR_HPP
#define AVAR_HPP

#include <iostream>
#include <exception>
#include <math.h>
#include <vector>

enum	TYPE { NOTYPE, RATIONAL, INDE, COMPLEX, MATRIX, POLY };

class Rational;

class AVar {
	public:
		virtual ~AVar() {};
		void    del(AVar *rhs, int toDelete);

		virtual TYPE			getType() const = 0;
		virtual	void			display() const = 0;
		virtual double			getVal() const;
		virtual std::vector< std::vector< Rational *> > getMat();
		virtual AVar    *add( AVar *rhs, int toDelete = 0);
		virtual AVar    *add( double rhs, int toDelete = 0);
		virtual AVar    *mul( AVar *rhs, int toDelete = 0);
		virtual AVar    *mul( double rhs, int toDelete = 0);
	private:

};



#endif