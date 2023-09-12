#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &src) {
	*this = src;
}

ASpell::ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &rhs) {
	this->name = rhs.name;
	this->effects = rhs.effects;

	return *this;
}

const std::string &ASpell::getName() const {
	return this->name;
}

const std::string &ASpell::getEffects() const {
	return this->effects;
}

void ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}
