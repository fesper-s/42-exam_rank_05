#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &src) {
	*this = src;
}

SpellBook::~SpellBook() {}

SpellBook &SpellBook::operator=(const SpellBook &rhs) {
	this->spells = rhs.spells;

	return *this;
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell)
		this->spells[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string const & spellName) {
	if (this->spells.find(spellName) != this->spells.end())
		this->spells.erase(this->spells.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const & spellName) {
	ASpell *buffer = NULL;
	if (this->spells.find(spellName) != this->spells.end())
		buffer = this->spells[spellName];
	return buffer;
}
