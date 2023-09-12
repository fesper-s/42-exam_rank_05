#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const Warlock &src) {
	*this = src;
}

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
}

Warlock &Warlock::operator=(const Warlock &rhs) {
	this->name = rhs.name;
	this->title = rhs.title;

	return *this;
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
		this->spellBook[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName) {
	if (this->spellBook.find(spellName) != this->spellBook.end())
		this->spellBook.erase(this->spellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
	if (this->spellBook.find(spellName) != this->spellBook.end())
		this->spellBook[spellName]->launch(target);
}
