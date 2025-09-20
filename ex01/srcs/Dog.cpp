/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:30 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:32:54 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Dog"
 * AÑADIR COSAS
 */

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

/**
 * @brief	Copy constructor
 * 			- Delegates to the base copy constructor
 * 
 * @param other	Another Dog object to copy from
 */
/*deep copy:
para que cada dog tenga su propio brain independiente
se crea una copia real del contenido del brain.
*/
Dog::Dog(const Dog& other) :	Animal(other),
								_brain(new Brain(*other._brain))
{
	std::cout << GREEN << "Dog Copy Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Assignment operator
 * 			- Reuses the base class assignment operator
 * 
 * @param other	Another dog object to assign from
 * @return	Reference to the current object
 */


Dog&	Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "Dog Assignment Operator called" 
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

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor called" 
				<< RESET << std::endl;
	delete this->_brain;
}

/**
 * @brief	Produces the sound of a dog.
 * 			- Overrides Animal::makeSound()
 * 
 */

void	Dog::makeSound() const
{
	std::cout << BLUE << "**Guau! Guau!**" << RESET << std::endl;
}

/**
 * @brief	
 * 
 */

void	Dog::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

/**
 * @brief	
 * 
 */

Brain& Dog::getBrain() const
{
	return(*this->_brain);
}
