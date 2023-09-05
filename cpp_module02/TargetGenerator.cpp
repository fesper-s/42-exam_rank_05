#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &src) {
	*this = src;
}

TargetGenerator::~TargetGenerator() {}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &rhs) {
	this->_target = rhs._target;
	return *this;
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		this->_target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	if (this->_target.find(target) != _target.end())
		this->_target.erase(this->_target.find(target));
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	ATarget *tmp = NULL;
	if (this->_target.find(target) != this->_target.end())
		tmp = this->_target[target];
	return (tmp);
}
