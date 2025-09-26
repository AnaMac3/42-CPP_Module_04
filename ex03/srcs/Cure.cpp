/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:53:52 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:58:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/**
 * @brief	Default constructor
 * 			- Calls base AMateria constructor with type "cure" 
 */

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure Default Constructor called" << RESET << std::endl;
}

/**
 * @brief	Copy Constructor
 * 			- uses assignment operator to copy base members 
 * 
 * @param other	Source Cure to copy from
 */

Cure::Cure(const Cure& other) : AMateria()
{
	std::cout << GREEN << "Cure Copy Constructor called" << RESET << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator
 * 			- Calls AMateria::operator= to copy base-class state
 * 			- If Cure later contains extra members, copy them here
 * 
 * @param other	Another Cure object to assign from
 * @return	Reference to the current object
 */

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << GREEN << "Cure Assignment Operator called" << RESET << std::endl;
	
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * @brief	Default destructor
 * 			- Virtual inhertied from AAMateria
 */

Cure::~Cure()
{
	std::cout << GREEN << "Cure Destructor called" << RESET << std::endl;
}

/**
 * @brief	Apply the cure effect on the target
 * 
 * @param target	Character being healed
 */

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " 
				<< target.getName() << "'s wounds *" << std::endl;
}

/**
 * @brief	Clone this Cure object
 * 			- Ensures polymorphic copying: caller receives a pointer to
 * 			a new Cure object and is responsible for deleting it.
 * 
 * @return AMateria*	A new heap-allocated Cure identical to this one
 */

AMateria* Cure::clone() const
{
	std::cout << GREEN << "Cure clone called" << RESET << std::endl;
	return (new Cure(*this));
}
