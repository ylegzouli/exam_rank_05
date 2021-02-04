#ifndef ATarget_HPP
#define ATarget_HPP

#include <string.h>
#include <iostream>
#include <vector>

class ASpell;

class ATarget
{
	private:
		std::string _type;
	
	public:
		ATarget(std::string type): _type(type){};
		virtual ~ATarget() {};
		
		ATarget() {};
		ATarget &operator=(const ATarget &ref) {_type = ref.getType(); return (*this); };
		ATarget(const ATarget &ref) {_type = ref.getType();};

		const std::string&	getType() const { return (_type); };
		virtual		ATarget*	clone() const = 0;
		
		void		getHitBySpell(const ASpell& ref) const;


};

#include "ASpell.hpp"

#endif
