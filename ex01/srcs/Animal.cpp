/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:50:59 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:16:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**
 * @brief	Default constructor
 * 
 */

Animal::Animal() :	_type("Default")
{
	std::cout << BG_GREEN << "Animal Default Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Copy constructor
 * 
 * @param other	Another Animal object to copy from
 */

Animal::Animal(const Animal& other)
{
	std::cout << BG_GREEN << "Animal Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator
 * 
 * @param other	Another Animal object to assign from
 * @return	Reference to the current object
 */

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << BG_GREEN << "Animal Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/**
 * @brief	Virtual destructor
 * 
 */

Animal::~Animal()
{
	std::cout << BG_GREEN << "Animal Destructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Gets the type of the animal
 * 
 * @return	A constant referente to '_type'
 */

std::string const	&Animal::getType() const
{
	return(this->_type);
}

/**
 * @brief	Sets the type of the animal
 * 
 * @param type	The new type as a string
 */

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

/**
 * @brief	Produces a generic sound
 * 
 */

void	Animal::makeSound() const
{
	std::cout << BG_BLUE << "**Default Sound**" << RESET << std::endl;
}
