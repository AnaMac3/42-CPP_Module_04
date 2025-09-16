/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:50:59 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:13:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() :	_type("Default"),
					_sound("Sound")
{
	std::cout << BG_GREEN << "Animal Default Constructor called" 
				<< RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BG_GREEN << "Animal Destructor called" 
				<< RESET << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << BG_GREEN << "Animal Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << BG_GREEN << "Animal Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		this->_sound = other._sound;
	}
	return (*this);
}

std::string const	&Animal::getType() const
{
	return(this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

void	Animal::setSound(const std::string &sound)
{
	this->_sound = sound;
}

void	Animal::makeSound() const
{
	std::cout << BLUE << this->_type << " makes: " << this->_sound 
				<< RESET << std::endl;
}