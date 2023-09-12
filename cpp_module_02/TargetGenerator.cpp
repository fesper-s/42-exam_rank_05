#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &src) {
	*this = src;
}

TargetGenerator::~TargetGenerator() {}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &rhs) {
	this->target = rhs.target;

	return *this;
}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (target)
		this->target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(const std::string &type) {
	if (this->target.find(type) != this->target.end())
		this->target.erase(this->target.find(type));
}

ATarget *TargetGenerator::createTarget(const std::string &type) {
	ATarget *buffer = NULL;
	if (this->target.find(type) != this->target.end())
		buffer = this->target[type];
	return buffer;
}
