#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

class ASpell {
	protected:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell(const ASpell &src);
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();

		ASpell &operator=(const ASpell &rhs);

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell *clone() const = 0;
};


#endif
