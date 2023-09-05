#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const ATarget &src) {
	*this = src;
}

ATarget::ATarget(const std::string &type) {
	this->type = type;
}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &rhs) {
	this->type = rhs.type;
	return *this;
}
const std::string &ATarget::getType() const {
	return this->type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
