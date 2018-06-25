
#ifndef POLY_HPP
#define POLY_HPP

#include "AVar.hpp"


class Poly : public AVar {
	public:
		Poly();
		Poly(Poly const & src);
		virtual ~Poly();

		Poly& operator=(Poly const& rhs);
        
		TYPE			getType() const;

        virtual	void			display() const;

	private:

};

#endif