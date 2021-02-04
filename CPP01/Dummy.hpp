#ifndef Dummy_HPP
#define Dummy_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
	public:
		Dummy(std::string type): ATarget(type){};
		virtual ~Dummy() {};
		
		Dummy(): ATarget("Target Practice Dummy") {};
		Dummy &operator=(const Dummy &ref) 
		{
			if (this != &ref)
				*this = ref;
			return (*this); 
		};
		Dummy(const Dummy &ref): ATarget(ref) {};
		virtual		Dummy*	clone() const 
		{
			return (new Dummy(*this));
		};


};


#endif
