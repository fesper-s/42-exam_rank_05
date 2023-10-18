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
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName) {
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
	const ATarget *test = 0;

	if (test == &target)
		return;
	ASpell *temp = spellBook.createSpell(spellName);
	if (temp)
		temp->launch(target);
}
