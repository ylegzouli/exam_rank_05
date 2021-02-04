#ifndef TargetGenerator_HPP
#define TargetGenerator_HPP

#include <string.h>
#include <iostream>
#include <vector>


class ASpell;
class ATarget;
#include "ATarget.hpp"
#include "ASpell.hpp"

class TargetGenerator
{
	private:
		std::vector<ATarget*> _list;

		TargetGenerator &operator=(const TargetGenerator &);
		TargetGenerator(const TargetGenerator&);
	
	public:
		TargetGenerator(){};
		virtual ~TargetGenerator()
		{
		};


		void		learnTargetType(ATarget *target)
		{
			for (std::vector<ATarget*>::iterator it = _list.begin(); it != _list.end(); it++)
			{
				if ((*(*it)).getType() == target->getType())
					return ;
			}
			_list.push_back(target->clone());
		};

		void		forgetTargetType(const std::string name)
		{
			for (std::vector<ATarget*>::iterator it = _list.begin(); it != _list.end();)
			{
				if ((*(*it)).getType() == name)
				{
					delete(*it);
					it = _list.erase(it);
				}
				else
					it++;
			}
		};

		ATarget		*createTarget(const std::string& name)
		{
			for (std::vector<ATarget*>::iterator it = _list.begin(); it != _list.end(); it++)
			{	
				if ((*(*it)).getType() == name)
				{
					return ((*(*it)).clone());
				}
			}
			return (NULL);
		};

};


#endif
