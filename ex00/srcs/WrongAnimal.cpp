/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:11 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:23:38 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :	_type("Wrong Default")
{
	std::cout << BG_YELLOW << "WrongAnimal Default Constructor called" 
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
		this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BG_YELLOW << "WrongAnimal Destructor called" 
				<< RESET << std::endl;
}

std::string const	&WrongAnimal::getType() const
{
	return(this->_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << BG_CYAN << "**Wrong default sound**"
				<< RESET << std::endl;
}
