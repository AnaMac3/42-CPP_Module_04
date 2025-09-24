#include "Cure.hpp"

/**
 * @brief	Default constructor
 * 			- Calls AMateria with "cure" as initialization type
 */

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure Default Constructor called" << std::endl;
}

/**
 * @brief	Default destructor
 * 			- Virtual heredado de AMateria
 */

Cure::~Cure()
{
	//std::cout << "Cure Destructor called" << std::endl;
}

/**
 * @brief	Copy Constructor
 * 			- delega en = operator.... está bien eso?
 * 
 * @param other	Cure to copy
 */

Cure::Cure(const Cure& other) : AMateria()
{
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = other;
}

/**
 * @brief	Assignation operator
 * 
 * @param other	Another Cure object to assign from
 * @return	Reference to the current object
 */

Cure&	Cure::operator=(const Cure& other)
{
	//std::cout << "Cure Assignment Operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=;
		//añadir mas cosas?
	}
	return (*this);
}

/**
 * @brief	Aplies the efect of the cure on the target
 * 			- Implementa el comportamiento concreto
 * 			- No debe gestioonar memoria ajena (qué significa eso?)
 * 
 * @param target	Target
 */

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " 
				<< target.getName() << "'s wounds *" << std::endl;
}

/**
 * @brief	Clone this Cure
 * 			- Returns heap memory, must be deleted/handled in the caller
 * 
 * @return	Pointer to a dynamic copy of the same class
 */

AMateria* Cure::clone() const //return a new instance of the same type
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}
