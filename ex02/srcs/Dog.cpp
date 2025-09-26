/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:30 by root              #+#    #+#             */
/*   Updated: 2025/09/26 18:58:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Dog"
 * 			- Allocates a new Brain instance
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
 * 			- Performs a deep copy of the other Dog, including Brain.
 * 
 * @param other	Another Dog object to copy from
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
 * 			- Performs a deep copy of the Brain
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
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

/**
 * @brief	Destructor
 * 			- Releases allocated Brain memory
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
 * @brief	Replaces the content of the dog's Brain with another Brain.
 * 
 * @param brain	A Brain object to copy from
 */

void	Dog::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

/**
 * @brief	Provides acces to the Brain of the dog.
 * 
 * @return Reference to the Brain owned by this dog.
 */

Brain& Dog::getBrain() const
{
	return(*this->_brain);
}
