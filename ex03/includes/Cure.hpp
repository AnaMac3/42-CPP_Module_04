#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

/**
 * @class	Cure
 * @brief	Concrete materia of Cure type
 * 			- Inherits from AMateria and implements clone() and use()
 * 			- Its clone returns a new Cure(*this)
 * 			- Its use() performs an specific action
 */

class Cure : public AMateria
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
