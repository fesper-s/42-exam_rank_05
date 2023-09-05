#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string type;
	public:
		ATarget();
		ATarget(const ATarget &src);
		ATarget(const std::string &type);
		~ATarget();

		ATarget &operator=(const ATarget &rhs);

		const std::string &getType() const;

		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;
};
