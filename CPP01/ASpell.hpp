#ifndef ASpell_HPP
#define ASpell_HPP

#include <string.h>
#include <iostream>
#include <vector>

class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
	
	public:
		ASpell(std::string name, std::string effects): _name(name), _effects(effects) {};
		virtual ~ASpell() {};
		
		ASpell() {};
		ASpell &operator=(const ASpell &ref) {_name = ref.getName(); _effects = ref.getEffects(); return (*this); };
		ASpell(const ASpell &ref) {_name = ref.getName(); _effects = ref.getEffects();};

		const std::string&	getName() const { return (_name); };
		const std::string&	getEffects() const { return (_effects); };
		virtual		ASpell*	clone() const = 0;

		void				launch(const ATarget& ref) const;

};

#include "ATarget.hpp"

#endif
