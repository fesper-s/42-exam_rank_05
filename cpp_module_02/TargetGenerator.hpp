#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
	private:
		std::map<std::string, ATarget *> target;

		TargetGenerator(const TargetGenerator &src);

		TargetGenerator &operator=(const TargetGenerator &rhs);
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target_ptr);
		void forgetTargetType(const std::string &type);
		ATarget *createTarget(const std::string &type);
};
