#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook {
	private:
		std::map<std::string, ASpell *> spells;

		SpellBook(const SpellBook &src);

		SpellBook &operator=(const SpellBook &rhs);
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spellName);
		ASpell *createSpell(const std::string &spellName);
};
