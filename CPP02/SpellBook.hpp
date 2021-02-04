#ifndef SpellBook_HPP
#define SpellBook_HPP

#include <string.h>
#include <iostream>
#include <vector>


class ASpell;
class ATarget;
#include "ATarget.hpp"
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::vector<ASpell*> _list;

		SpellBook &operator=(const SpellBook &);
		SpellBook(const SpellBook&);
	
	public:
		SpellBook(){};
		virtual ~SpellBook()
		{
		};


		void		learnSpell(ASpell *spell)
		{
			for (std::vector<ASpell*>::iterator it = _list.begin(); it != _list.end(); it++)
			{
				if ((*(*it)).getName() == spell->getName())
					return ;
			}
			_list.push_back(spell->clone());
		};

		void		forgetSpell(const std::string name)
		{
			for (std::vector<ASpell*>::iterator it = _list.begin(); it != _list.end();)
			{
				if ((*(*it)).getName() == name)
				{
					delete(*it);
					it = _list.erase(it);
				}
				else
					it++;
			}
		};

		ASpell		*createSpell(const std::string& name)
		{
			for (std::vector<ASpell*>::iterator it = _list.begin(); it != _list.end(); it++)
			{	
				if ((*(*it)).getName() == name)
				{
					return ((*(*it)).clone());
				}
			}
			return (NULL);
		};

};


#endif
