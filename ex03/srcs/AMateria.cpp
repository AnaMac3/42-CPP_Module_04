/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:39:13 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:47:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/**
 * @brief	Default constructor
 * 
 */
AMateria::AMateria() : _type("default")
{
	std::cout << BG_GREEN << "AMateria Default Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Type constructor
 * 
 * @param type	The type for this materia
 */

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << BG_GREEN << "AMateria Type Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Copy constructor
 * 
 * @param other	AMateria to copy from.
 */

AMateria::AMateria(const AMateria& other)
{
	std::cout << BG_GREEN << "AMateria Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator
 * 
 * @param other	AMateria to assign from
 * @return	Reference to *this
 */

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << BG_GREEN << "AMateria Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/**
 * @brief	Virtual Destructor to allow deletion through base pointers
 * 
 */

AMateria::~AMateria()
{
	std::cout << BG_GREEN << "AMateria Destructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Return the materia type identifier
 * 
 * @return	const reference to the type string
 */

std::string const	&AMateria::getType() const
{
	//std::cout << BG_GREEN << "AMateria getType called" << RESET << std::endl;
	return(this->_type);
}

/**
 * @brief	Apply the materia effect to the target
 * 			- Derived classes override this method to implement concrete
 * 			behaviour
 * 
 * @param target	A reference to the ICharacter that receives the effect
 */

void	AMateria::use(ICharacter& target)
{
	std::cout << BG_GREEN << "AMateria use method called" 
				<< target.getName() << " name" << RESET << std::endl;
}
