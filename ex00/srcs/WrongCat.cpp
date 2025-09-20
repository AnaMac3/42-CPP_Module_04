/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:18 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:23:25 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << YELLOW << "WrongCat Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Wrong Cat";
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

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat Destructor called" 
				<< RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << CYAN << "**CUAC! CUAAC!**" << RESET << std::endl;
}
