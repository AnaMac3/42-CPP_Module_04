/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:30 by root              #+#    #+#             */
/*   Updated: 2025/09/16 16:07:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Dog";
	this->_sound = "Guau Guau!!";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor called" 
				<< RESET << std::endl;
	delete this->_brain;
}

/*deep copy:
para que cada dog tenga su propio brain independiente
se crea una copia real del contenido del brain.
*/
Dog::Dog(const Dog& other) :	Animal(other),
								_brain(new Brain(*other._brain))
{
	std::cout << GREEN << "Dog Copy Constructor called" 
				<< RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "Dog Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

void	Dog::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

Brain& Dog::getBrain() const
{
	return(*this->_brain);
}
