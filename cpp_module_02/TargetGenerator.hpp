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

		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};
