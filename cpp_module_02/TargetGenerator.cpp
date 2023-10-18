#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget *>::iterator it_begin = this->target.begin();
	std::map<std::string, ATarget *>::iterator it_end = this->target.end();

	while (it_begin != it_end) {
		delete it_begin->second;
		++it_begin;
	}
	this->target.clear();
}

void TargetGenerator::learnTargetType(ATarget *target_ptr) {
	if (target_ptr)
		target.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &type) {
	std::map<std::string, ATarget *>::iterator it = target.find(type);

	if (it != target.end())
		delete it->second;
	target.erase(type);
}

ATarget *TargetGenerator::createTarget(const std::string &type) {
	std::map<std::string, ATarget *>::iterator it = target.find(type);

	if (it != target.end())
		return target[type];
	return NULL;
}
