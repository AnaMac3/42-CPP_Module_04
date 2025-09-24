#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include "ICharacter.hpp"

/**
 * @class	AMateria
 * @brief	Abstract class which represents a generic "materia".
 * 			This is the base cñass for the concrete types of materia (Ice, Cure).
 * 			Provies:
 * 			- A type identifier
 * 			- A clone interface to allow deep copies for runtime type
 * 			- A virtual method use() which aplies the efect upon a ICharacter
 * 
 * 			Properties:
 * 			- Ownership: the class doesn't free the materias pointed by others;
 * 			who creates a new AMateria must decide if transfers the ownership (?¿¿?)
 * 			- clone(): key method for implementing deep copy in classes with
 * 			pointers to AMateria
 * 			- Copy constructor and operator= are public to allow copies from
 * 			outside
 */

class AMateria
{
	protected:
		AMateria();

		std::string _type;

	public:
		AMateria(std::string const &type); 

		virtual ~AMateria();

		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);

		std::string const &getType() const; //returns the materia type

		virtual AMateria* clone() const = 0; //pure virtual -> returns a pointer to a new instance of the same dynamic obj
		virtual void use(ICharacter& target); //uses interface...
};

#endif
