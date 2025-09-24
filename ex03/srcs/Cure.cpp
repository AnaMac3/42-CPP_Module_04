#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria()
{
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = other;
}

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

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " 
				<< target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const //return a new instance of the same type
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}
