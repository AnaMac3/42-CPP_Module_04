/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:11 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:39:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :	_type("Wrong Default"),
								_sound("Noise")
{
	std::cout << BG_YELLOW << "WrongAnimal Default Constructor called" 
				<< RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BG_YELLOW << "WrongAnimal Destructor called" 
				<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << BG_YELLOW << "WrongAnimal Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << BG_YELLOW << "WrongAnimal Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		this->_sound = other._sound;
	}
	return (*this);
}

std::string const	&WrongAnimal::getType() const
{
	return(this->_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

void	WrongAnimal::setSound(const std::string &sound)
{
	this->_sound = sound;
}

void	WrongAnimal::makeSound() const
{
	std::cout << CYAN << this->_type << " makes: " << this->_sound 
				<< RESET << std::endl;
}
