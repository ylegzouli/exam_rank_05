#include "ASpell.hpp"

void
ASpell::launch(const ATarget &ref) const
{
	ref.getHitBySpell((*this));
}
