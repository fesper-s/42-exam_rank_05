#pragma once

#include <iostream>

class ATarget;

class ASpell {
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &src);
		virtual ~ASpell();

		ASpell &operator=(const ASpell &rhs);

		const std::string &getName() const;
		const std::string &getEffects() const;

		void launch(const ATarget &target) const;

		virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"
