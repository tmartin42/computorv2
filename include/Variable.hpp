
#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <exception>
#include <math.h>
#include <vector>


enum	TYPE { NOTYPE, RATIONAL, INDE, COMPLEX, MATRIX, POLY };
enum	CALC { UNKNOWN, ADD, MINUS, MUL, DIV, MOD, SCAL, POW };

class Variable {
	public:
		Variable();
		Variable(double val);

		Variable(std::vector< std::vector<Variable> > matrix);
		Variable(Variable const & src);
		virtual ~Variable();

		Variable& operator=(Variable const& rhs);
        
		TYPE			getType() const;

        void            display() const;

        double  getRat() const;
        void    setRat(double newVal);
        std::vector< std::vector<Variable> >  getMat() const;
        void    setMat(std::vector< std::vector<Variable> > matrix);
        Variable    scalMatToMat(std::vector< std::vector<Variable> > rhsMat);
        Variable    calcMatToMat(std::vector< std::vector<Variable> > rhsMat, CALC calc) const;
        Variable    calcRatToMatrix(Variable const &rhs, CALC calc) const;
        Variable    poww(int poww);
        Variable    operator+( Variable const &rhs ) ;
        Variable    operator-( Variable const &rhs ) ;
        Variable    operator*( Variable const &rhs ) ;
        Variable    operator/( Variable const &rhs ) ;
        Variable    operator%( Variable const &rhs ) ;

	private:
        double 	_val;
		TYPE 	_type;
        std::vector< std::vector<Variable> > _matrix;
};

#endif