/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:39:13 by root              #+#    #+#             */
/*   Updated: 2025/09/26 12:09:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << BG_GREEN << "AMateria Default Constructor called" 
				<< RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << BG_GREEN << "AMateria Type Constructor called" 
				<< RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << BG_GREEN << "AMateria Destructor called" 
				<< RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << BG_GREEN << "AMateria Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << BG_GREEN << "AMateria Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	//std::cout << BG_GREEN << "AMateria getType called" << RESET << std::endl;
	return(this->_type);
}

/**
 * @brief	Aplies the efecto of the materia on the target
 * 			Implementación por defecto que puede hacer login o no hacer nada
 * 			significativo. ¿Cómo se haría login?
 * 			Las clases derivadas sobreescriben use() para ejecutar el comportamient
 * 			real
 * 			ESTE MENSAJE NUNCA DEBERIA IMPRIMIRSE PORQUE ICE Y CURE SOBREESCRIBEN
 * 			ESTE MÉTODO
 * 
 * @param target	Objetivo sobre el qu se aplica el efecto
 */

void	AMateria::use(ICharacter& target)
{
	std::cout << BG_GREEN << "AMateria use method called with " 
				<< target.getName() << " name" << RESET << std::endl;
}