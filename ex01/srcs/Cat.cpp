/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:19 by root              #+#    #+#             */
/*   Updated: 2025/09/16 16:10:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor called" 
				<< RESET << std::endl;
	this->_type = "Cat";
	this->_sound = "Miaaauuuu";
	//crear Brain* con new Brain()
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor called" 
				<< RESET << std::endl;
	//delete Brain
	delete this->_brain;
}

/*deep copy:
para que cada dog tenga su propio brain independiente
se crea una copia real del contenido del brain.
*/
Cat::Cat(const Cat& other) :	Animal(other),
								_brain(new Brain(*other._brain))
{
	std::cout << GREEN << "Cat Copy Constructor called" 
				<< RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << GREEN << "Cat Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

void	Cat::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

Brain& Cat::getBrain() const
{
	return(*this->_brain);
}
