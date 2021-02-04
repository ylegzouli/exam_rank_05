#ifndef Fwoosh_HPP
#define Fwoosh_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class ASpell;

class Fwoosh: public ASpell
{
	public:
		Fwoosh(std::string name, std::string effects): ASpell(name, effects){};
		virtual ~Fwoosh() {};
		
		Fwoosh(): ASpell("Fwoosh", "fwooshed") {};
		Fwoosh &operator=(const Fwoosh &ref) 
		{
			if (this != &ref)
				*this = ref;
			return (*this); 
		};
		Fwoosh(const Fwoosh &ref): ASpell(ref) {};
		virtual		Fwoosh*	clone() const 
		{
			return (new Fwoosh(*this));
		};


};


#endif
