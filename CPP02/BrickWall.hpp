#ifndef BrickWall_HPP
#define BrickWall_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class ATarget;

class BrickWall: public ATarget
{
	public:
		BrickWall(std::string type): ATarget(type){};
		virtual ~BrickWall() {};
		
		BrickWall(): ATarget("Inconspicuous Red-brick Wall") {};
		BrickWall &operator=(const BrickWall &ref) 
		{
			if (this != &ref)
				*this = ref;
			return (*this); 
		};
		BrickWall(const BrickWall &ref): ATarget(ref) {};
		virtual		BrickWall*	clone() const 
		{
			return (new BrickWall(*this));
		};


};


#endif
