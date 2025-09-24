#include "Ice.hpp"

/**
 * @brief	Default constructor
 * 			- Calls AMateria with "ice" as initialization type
 */

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice Default Constructor called" << std::endl;
}

/**
 * @brief	Default destructor
 * 			- Virtual heredado de AMateria
 */

Ice::~Ice()
{
	//std::cout << "Ice Destructor called" << std::endl;
}

/**
 * @brief	Copy Constructor
 * 			- delega en = operator.... está bien eso?
 * 
 * @param other	Ice to copy
 */

Ice::Ice(const Ice& other) : AMateria()
{
	//std::cout << "Ice Copy Constructor called" << std::endl;
	*this = other;
}

/**
 * @brief	Assignation operator
 * 
 * @param other	Another Ice object to assign from
 * @return	Reference to the current object
 */

Ice&	Ice::operator=(const Ice& other)
{
	//std::cout << "Ice Assignment Operator called" << std::endl;
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
 * 			- No debe gestionar memoria ajena (qué significa eso?)
 * 
 * @param target	Target
 */

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " 
				<< target.getName() << " *" << std::endl;
}

/**
 * @brief	Clone this Ice
 * 			- Returns heap memory, must be deleted/handled in the caller
 * 
 * @return	Pointer to a dynamic copy of the same class
 */

AMateria* Ice::clone() const //return a new instance of the same type
{
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}
