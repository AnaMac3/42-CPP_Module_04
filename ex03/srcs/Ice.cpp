#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice Default Constructor called" << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria()
{
	std::cout << "Ice Copy Constructor called" << std::endl;
	*this = other;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << "Ice Assignment Operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=;
		//añadir mas cosas?
	}
	return (*this);
}

void	Ice::use(ICharacter& target) : AMateria()
{
	std::cout << "* shoots an ice bolt at <name> *" << std::endl;
}


AMateria* Ice::clone() const
{
	//return a new instance of the same type
}
