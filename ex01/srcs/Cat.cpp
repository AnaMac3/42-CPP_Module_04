/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:19 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:31:28 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Cat"
 * AÑADIR COSAS
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
 * 			- Delegates to the base copy constructor
 * 
 * @param other	Another Cat object to copy from
 */
/*deep copy:
para que cada dog tenga su propio brain independiente
se crea una copia real del contenido del brain.
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
 * AÑADIR COSAS
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
 * AÑADIR COSAS
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
 * @brief	
 * 
 */

void	Cat::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

/**
 * @brief	
 * 
 */

Brain& Cat::getBrain() const
{
	return(*this->_brain);
}
