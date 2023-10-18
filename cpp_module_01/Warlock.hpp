#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock {
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> spells;

		Warlock();
		Warlock(const Warlock &src);

		Warlock &operator=(Warlock const &rhs);
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const; 
		void setTitle(const std::string &title);

		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget &target);
};
