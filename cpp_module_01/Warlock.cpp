#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) {
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const {
	return this->name;
}

const std::string &Warlock::getTitle() const {
	return this->title;
}

void Warlock::setTitle(const std::string &title) {
	this->title = title;
}

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
	if (spell)
		spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spellName) {
	std::map<std::string, ASpell *>::iterator it = spells.find(spellName);
	if (it != spells.end())
		delete it->second;
	spells.erase(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
	ASpell *spell = spells[spellName];
	if (spell)
		spell->launch(target);
}
