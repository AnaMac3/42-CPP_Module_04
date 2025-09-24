#ifndef Ice_HPP
# define Ice_HPP

# include "AMateria.hpp"

/**
 * @class	Ice
 * @brief	
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
