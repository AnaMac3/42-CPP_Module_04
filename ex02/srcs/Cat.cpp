/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:19 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:31:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Cat"
 * 			- Allocates a new Brain instance
 * 
 */

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor called" 
				<< RESET << std::endl;
			
	this->_type = "Cat";
	this->_brain = new Brain();
}

/**
 * @brief	Copy constructor
 * 			- Performes a deep copy of the other Cat, including Brain.
 * 
 * @param other	Another Cat object to copy from
 */

Cat::Cat(const Cat& other) :	Animal(other),
								_brain(new Brain(*other._brain))
{
	std::cout << GREEN << "Cat Copy Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Assignment operator
 * 			- Reuses the base class assignment operator
 * 			- Performs a deep copy of the Brain
 * 
 * @param other	Another Cat object to assign from
 * @return	Reference to the current object
 */

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "Cat Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

/**
 * @brief	Destructor
 * 			- Releases allocated Brain memory
 * 
 */

Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor called" 
				<< RESET << std::endl;
	delete this->_brain;
}

/**
 * @brief	Produces the sound of a cat.
 * 			- Overrides Animal::makeSound()
 * 
 */

void	Cat::makeSound() const
{
	std::cout << BLUE << "**Miaaauu**" << RESET << std::endl;
}

/**
 * @brief	Replaces the content of the cat's Brain with another Brain.
 * 
 * @param brain	A Brain object to copy from.
 */

void	Cat::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

/**
 * @brief	Provides access to the Brain of the cat.
 * 
 * @return Reference to the Brain owned by this cat.
 */

Brain& Cat::getBrain() const
{
	return(*this->_brain);
}
