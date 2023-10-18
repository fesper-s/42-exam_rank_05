#pragma once

#include <iostream>

class ASpell;

class ATarget {
	protected:
		std::string type;
	public:
		ATarget();
		ATarget(const ATarget &src);
		ATarget(const std::string &type);
		virtual ~ATarget();

		ATarget &operator=(const ATarget &rhs);
		
		const std::string &getType() const;

		void getHitBySpell(const ASpell &spell) const;

		virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"
