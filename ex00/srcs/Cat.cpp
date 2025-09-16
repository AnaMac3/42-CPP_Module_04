/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:19 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:12:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Cat";
	this->_sound = "Miaaauuuu";
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor called" 
				<< RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << GREEN << "Cat Copy Constructor called" 
				<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "Cat Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}
