#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include "ASpell.hpp"
# include <vector>

class SpellBook {
	private:
		std::vector<ASpell *> spellBook;

		SpellBook(const SpellBook &src);

		SpellBook &operator=(const SpellBook &rhs);
	public:
		SpellBook();
		virtual ~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spellName);
		ASpell *createSpell(const std::string &spellName);
};

#endif
