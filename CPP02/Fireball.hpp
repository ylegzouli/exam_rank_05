#ifndef Fireball_HPP
#define Fireball_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class ASpell;

class Fireball: public ASpell
{
	public:
		Fireball(std::string name, std::string effects): ASpell(name, effects){};
		virtual ~Fireball() {};
		
		Fireball(): ASpell("Fireball", "burn to a crisp") {};
		Fireball &operator=(const Fireball &ref) 
		{
			if (this != &ref)
				*this = ref;
			return (*this); 
		};
		Fireball(const Fireball &ref): ASpell(ref) {};
		virtual		Fireball*	clone() const 
		{
			return (new Fireball(*this));
		};


};


#endif
