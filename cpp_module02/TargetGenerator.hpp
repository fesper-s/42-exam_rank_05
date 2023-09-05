#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> _target;

		TargetGenerator(const TargetGenerator &src);

		TargetGenerator &operator=(const TargetGenerator &rhs);
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &target);
		ATarget *createTarget(std::string const &target);
};
