#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &src) {
	*this = src;
}

SpellBook::~SpellBook() {}

SpellBook &SpellBook::operator=(const SpellBook &rhs) {
	this->spellBook = rhs.spellBook;
	return *this;
}

void SpellBook::learnSpell(ASpell *spell) {
	if (spell)
		this->spellBook[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string const &spellName) {
	if (this->spellBook.find(spellName) != this->spellBook.end())
		this->spellBook.erase(this->spellBook.find(spellName));
}

ASpell *SpellBook::createSpell(std::string const &spellName) {
	ASpell *tmp = NULL;
	if (this->spellBook.find(spellName) != this->spellBook.end())
		tmp = this->spellBook[spellName];
	return (tmp);
}
