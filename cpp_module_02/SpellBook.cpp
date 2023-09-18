#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::vector<ASpell *>::iterator ite = this->spellBook.end();
	for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it)
		delete *it;
	this->spellBook.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell *>::iterator ite = this->spellBook.end();
		for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->spellBook.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(const std::string &spellName) {
	std::vector<ASpell *>::iterator ite = this->spellBook.end();
	for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			it = this->spellBook.erase(it);
		}
	}
}

ASpell *SpellBook::createSpell(const std::string &spellName) {
	std::vector<ASpell *>::iterator ite = this->spellBook.end();
	for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName)
			return *it;
	}
	return NULL;
}
