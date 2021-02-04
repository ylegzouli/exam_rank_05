#ifndef Polymorph_HPP
#define Polymorph_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class ASpell;

class Polymorph: public ASpell
{
	public:
		Polymorph(std::string name, std::string effects): ASpell(name, effects){};
		virtual ~Polymorph() {};
		
		Polymorph(): ASpell("Polymorph", "turned into a criter") {};
		Polymorph &operator=(const Polymorph &ref) 
		{
			if (this != &ref)
				*this = ref;
			return (*this); 
		};
		Polymorph(const Polymorph &ref): ASpell(ref) {};
		virtual		Polymorph*	clone() const 
		{
			return (new Polymorph(*this));
		};


};


#endif
