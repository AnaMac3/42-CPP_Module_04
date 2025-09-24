#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria()
{
	//std::cout << "Ice Copy Constructor called" << std::endl;
	*this = other;
}

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

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " 
				<< target.getName() << " *" << std::endl;
}


AMateria* Ice::clone() const //return a new instance of the same type
{
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}
