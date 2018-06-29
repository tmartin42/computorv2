
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include "AVar.hpp"


class Rational : public AVar {
	public:
		Rational();
		Rational(double val);
		Rational(Rational const & src);
		virtual ~Rational();

		Rational& operator=(Rational const& rhs);
        
		TYPE			getType() const;

        void            display() const;

        double  getVal() const;
        void    setVal(double newVal);
        AVar    *Add( AVar *rhs, int toDelete = 0 ) 
      /*  AVar    &operator+( AVar  &rhs ) ;
        AVar    &operator-( AVar  &rhs ) ;*/
     //   AVar   &operator/( AVar  &rhs ) ;
      //  AVar   &operator*( AVar  &rhs ) ;
     //   AVar    &operator%( AVar  &rhs ) ;

	private:
        double _val;
};



#endif