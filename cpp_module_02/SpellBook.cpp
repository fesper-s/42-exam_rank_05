#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator it_begin = this->spells.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->spells.end();

	while (it_begin != it_end) {
		delete it_begin->second;
		++it_begin;
	}
	this->spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	if (spell)
		spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string &spellName) {
	std::map<std::string, ASpell *>::iterator it = spells.find(spellName);

	if (it != spells.end())
		delete it->second;
	spells.erase(spellName);
}

ASpell *SpellBook::createSpell(const std::string &spellName) {
	std::map<std::string, ASpell *>::iterator it = spells.find(spellName);

	if (it != spells.end())
		return spells[spellName];
	return NULL;
}
