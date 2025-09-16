/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:30 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:14:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Dog";
	this->_sound = "Guau Guau!!";
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor called" 
				<< RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GREEN << "Dog Copy Constructor called" 
				<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "Dog Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}
