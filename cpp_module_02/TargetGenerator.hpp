#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <vector>

class TargetGenerator {
	private:
		std::vector<ATarget *> target;

		TargetGenerator(const TargetGenerator &src);

		TargetGenerator &operator=(const TargetGenerator &rhs);
	public:
		TargetGenerator();
		virtual ~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(const std::string &type);
		ATarget *createTarget(const std::string &type);
};

#endif
