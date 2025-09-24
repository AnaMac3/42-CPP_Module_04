#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

/**
 * @class	Cure
 * @brief	
 */

class Cure
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);

		void use(ICharacter& target);
		AMateria* clone() const; //??
};

#endif
