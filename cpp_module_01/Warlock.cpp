#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title) {
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
	if (spell) {
		std::vector<ASpell *>::iterator ite = this->spellBook.end();
		for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		this->spellBook.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(std::string spellName) {
	std::vector<ASpell *>::iterator ite = this->spellBook.end();
	for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			it = this->spellBook.erase(it);
		}
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
	std::vector<ASpell *>::iterator ite = this->spellBook.end();
	for (std::vector<ASpell *>::iterator it = this->spellBook.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
			return ;
		}
	}
}
