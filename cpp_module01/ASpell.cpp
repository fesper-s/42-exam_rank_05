#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &src) {
	*this = src;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &rhs) {
	this->_name = rhs.getName();
	this->_effects = rhs.getEffects();
	return *this;
}

std::string ASpell::getName() const {
	return this->_name;
}

std::string ASpell::getEffects() const {
	return this->_effects;
}
