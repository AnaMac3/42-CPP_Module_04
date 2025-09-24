#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	//std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	//std::cout << "AMateria Constructor called" << std::endl;
	this->_type = type;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	//std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	//std::cout << "AMateria Assignment Operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return(this->_type);
}

/**
 * @brief	Aplies the efecto of the materia on the target
 * 			Implementación por defecto que puede hacer login o no hacer nada
 * 			significativo. ¿Cómo se haría login?
 * 			Las clases derivadas sobreescriben use() para ejecutar el comportamient
 * 			real
 * 
 * @param target	Objetivo sobre el qu se aplica el efecto
 */
void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use method called with " 
				<< target.getName() << " name" << std::endl;
	//NO SE QUÉ HABRIA QUE PONER AQUÍ
}