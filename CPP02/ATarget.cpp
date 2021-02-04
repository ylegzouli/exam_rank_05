#include "ATarget.hpp"

void
ATarget::getHitBySpell(const ASpell &ref) const
{
	std::cout << _type << " has been " << ref.getEffects() <<     "!\n";
}
