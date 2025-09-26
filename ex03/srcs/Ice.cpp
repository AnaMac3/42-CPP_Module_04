/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:59:50 by root              #+#    #+#             */
/*   Updated: 2025/09/26 17:02:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/**
 * @brief	Default constructor
 * 			- Calls base AMateria constructor with type "ice" 
 */

Ice::Ice() : AMateria("ice")
{
	std::cout << BLUE << "Ice Default Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Copy Constructor
 * 			- uses assignment operator to copy base members 
 * 
 * @param other	Source Ice to copy from
 */

Ice::Ice(const Ice& other) : AMateria()
{
	std::cout << BLUE << "Ice Copy Constructor called" << RESET << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator
 * 			- Calls AMateria::operator= to copy base-class state
 * 			- If Cure later contains extra members, copy them here
 * 
 * @param other	Another Ice object to assign from
 * @return	Reference to the current object
 */

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << BLUE << "Ice Assignment Operator called" << RESET << std::endl;
	
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * @brief	Default destructor
 * 			- Virtual inhertied from AAMateria
 */

Ice::~Ice()
{
	std::cout << BLUE << "Ice Destructor called" << RESET << std::endl;
}

/**
 * @brief	Apply the cure effect on the target
 * 
 * @param target	Character being healed
 */

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " 
				<< target.getName() << " *" << std::endl;
}

/**
 * @brief	Clone this Ice object
 * 			- Ensures polymorphic copying: caller receives a pointer to
 * 			a new Cure object and is responsible for deleting it.
 * 
 * @return AMateria*	A new heap-allocated Cure identical to this one
 */

AMateria* Ice::clone() const
{
	std::cout << BLUE << "Ice clone called" << RESET << std::endl;
	return (new Ice(*this));
}
