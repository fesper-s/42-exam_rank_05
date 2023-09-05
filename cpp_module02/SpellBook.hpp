#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		SpellBook(const SpellBook &src);

		SpellBook &operator=(const SpellBook &rhs);

		std::map<std::string, ASpell *> spellBook;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &spellName);
};
