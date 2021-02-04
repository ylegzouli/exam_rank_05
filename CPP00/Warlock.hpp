#ifndef Warlock_HPP
#define Warlock_HPP

#include <string.h>
#include <iostream>
#include <vector>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
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
};

#endif
