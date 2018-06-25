
#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <exception>
#include <math.h>
#include <vector>


enum	TYPE { NOTYPE, RATIONAL, INDE, COMPLEX, MATRIX, POLY };

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

        Variable    addToMatrix(Variable const &rhs) const;
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
