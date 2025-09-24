#ifndef Ice_HPP
# define Ice_HPP

# include "AMateria.hpp"

/**
 * @class	Ice
 * @brief	Concrete materia of Ice type
 * 			- Inherits from AMateria and implements clone() and use()
 * 			- Its clone returns a new Ice(*this)
 * 			- Its use() performs an specific action
 */

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);

		void use(ICharacter& target);
		AMateria* clone() const; //??
};

#endif
