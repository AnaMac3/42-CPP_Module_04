/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:18 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:46:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << YELLOW << "WrongCat Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "panther";
	this->_sound = "GRRRRRR";
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat Destructor called" 
				<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << YELLOW << "WrongCat Copy Constructor called" 
				<< RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << YELLOW <<  "WrongCat Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}
