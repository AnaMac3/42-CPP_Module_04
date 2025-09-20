/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:19 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:18:07 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief	Default constructor
 * 			- Calls the base constructor
 * 			- Sets '_type' to "Cat"
 */

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Cat";
}

/**
 * @brief	Copy constructor
 * 			- Delegates to the base copy constructor
 * 
 * @param other	Another Cat object to copy from
 */

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << GREEN << "Cat Copy Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Assignment operator
 * 			- Reuses the base class assignment operator
 * 
 * @param other	Another Cat object to assign from
 * @return	Reference to the current object
 */

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "Cat Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/**
 * @brief	Destructor
 * 
 */

Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor called" 
				<< RESET << std::endl;
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
