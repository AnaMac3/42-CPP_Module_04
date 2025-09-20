/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:30 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:18:37 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Dog"
 */

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Dog";
}

/**
 * @brief	Copy constructor
 * 			- Delegates to the base copy constructor
 * 
 * @param other	Another Dog object to copy from
 */

Dog::Dog(const Dog& other) : Animal(other)
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
		Animal::operator=(other);
	return (*this);
}

/**
 * @brief	Destructor
 * 
 */

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor called" 
				<< RESET << std::endl;
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
