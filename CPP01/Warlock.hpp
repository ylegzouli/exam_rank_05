#ifndef Warlock_HPP
#define Warlock_HPP

#include <string.h>
#include <iostream>
#include <vector>


class ASpell;
class ATarget;
#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		std::vector<ASpell*> _list;

		Warlock();
		Warlock &operator=(const Warlock &);
		Warlock(const Warlock&);
	
	public:
		Warlock(std::string name, std::string title): _name(name), _title(title)
		{
			std::cout << _name << ": This looks like another boring day.\n";
		};
		virtual ~Warlock()
		{
			std::cout << _name << ": My job here is done!\n";
		};

		const std::string&	getName() const { return (_name); };
		const std::string&	getTitle() const { return (_title); };

		void			setTitle(const std::string &title) { _title = title; };
		void			introduce() const
		{
			std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
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

		void		forgetSpell(std::string name)
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

		void		launchSpell(std::string name, ATarget &ref)
		{
			for (std::vector<ASpell*>::iterator it = _list.begin(); it != _list.end(); it++)
			{	
				if ((*(*it)).getName() == name)
				{
					(*(*it)).launch(ref);
				}
			}
		};

};


#endif
