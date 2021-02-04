#ifndef Warlock_HPP
#define Warlock_HPP

#include <string.h>
#include <iostream>
#include <vector>


class ASpell;
class ATarget;
class SpellBook;
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook	_book;

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
			_book.learnSpell(spell);
		};

		void		forgetSpell(std::string name)
		{
			_book.forgetSpell(name);
		};

		void		launchSpell(std::string name, ATarget &ref)
		{
			ASpell *elem = _book.createSpell(name);
			if (elem != NULL)
				elem->launch(ref);
		};

};


#endif
