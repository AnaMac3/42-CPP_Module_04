#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria Constructor called" << std::endl;
	this->_type = type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return(this->_type);
}

void	AMateria::use(ICharacter& target)
{
	//display
	//ice: "*shoots an ice bolt at <name> *"
	//cure: "*heals <name>'s wounds*"
	//name is the name of the Character passed as parameter
	//SUPONGO QUE AQUÍ EN LA CLASE ABSTRACTA SE RECOGERÁ DE ALGUNA MANERA EL NAME
	//Y EN LAS CLASES CONCRETAS DERIVADAS SE SACA EL MENSAJE??

	
}