
#ifndef INDE_HPP
#define INDE_HPP

#include "AVar.hpp"


class Inde : public AVar {
	public:
		Inde();
		Inde(Inde const & src);
		virtual ~Inde();

		Inde& operator=(Inde const& rhs);
        
		TYPE			getType() const;

        virtual	void			display() const;

	private:

};

#endif