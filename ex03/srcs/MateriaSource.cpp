/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:30:33 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:31:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/**
 * @brief	Default constructor
 * 			- Initializes all Materia slots (_list) to NULL
 * 
 */

MateriaSource::MateriaSource()
{
	std::cout << YELLOW << "MateriaSource Default Constructor called" 
				<< RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
		this->_list[i] = NULL;
}

/**
 * @brief	Copy Constructor
 * 			- Initializes all Materia slots to NULL first
 * 			- Deep copies all stored Materias via assignment operator
 * 			- Each Materia in _list is a clone of other's Materia
 * 
 * @param other	Another MateriaSource to copy from
 */

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << YELLOW << "MateriaSource Copy Constructor called" 
				<< RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_list[i] = NULL;
	*this = other;
}

/**
 * @brief	Assignment Operator
 * 			- Avoids self-assignment
 * 			- Deletes all currently stored Materias in this
 * 			- Deep copies all stored Materias by cloning all Materis from
 * 			other into this object
 * 			- If a slot in other is empty, sets the corresponding slot in
 * 			this to NULL
 * 
 * @param other	Another MateriaSource to assign from
 * @return Reference to this MateriaSource
 */

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << YELLOW << "MateriaSource Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_list[i])
				delete this->_list[i];
			if (other._list[i])
				this->_list[i] = other._list[i]->clone();
			else
				this->_list[i] = NULL;
		}
	}
	return (*this);
}

/**
 * @brief	Default Destructor
 * 			- Deletes all stored Materias to prevent memory leaks
 */

MateriaSource::~MateriaSource()
{
	std::cout << YELLOW << "MateriaSource Destructor called" 
				<< RESET << std::endl;
	for (int i = 0; i < 4; i ++)
	{
		if (this->_list[i])
			delete this->_list[i];
	}
}

/**
 * @brief	Stores a clone of the given Materia in the first  available slot.
 * 			- If m is NULL, the function does nothing and logs an error
 * 			- If all slots are already filled, logs an error and ignores
 * 			the Materia
 * 			- Otherwise, clones m and stores it in the first empty slot
 * 
 * @param m	Pointer to an AMateria to be learned
 */

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << "==> Cannot learn NULL materia" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i ++)
	{
		if (!this->_list[i])
		{
			this->_list[i] = m->clone();
			std::cout << CYAN << "==> Materia " << m->getType() 
					<< " learned in MateriaSource" << RESET << std::endl; 
			return ;
		}
	}
	std::cout << RED << "==> Cannot learn more materials, MateriaSource is full!"
					<< RESET << std::endl;
}

/**
 * @brief	Creates a new Materia by searching for a stored template with the
 * 			given type
 * 			- Iterates through the 4 slots in _list
 * 			- If a stored Materia's _type matches type, clones and returns it
 * 			- If no match is found, logs an error and returns NULL
 * 
 * @param type	String identifying the type of Materia to create
 * @return AMateria* Pointer to a new cloned Materia, or NULL if type is unknown
 */

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_list[i] && this->_list[i]->getType() == type)
		{
			std::cout << CYAN << "==> Materia of type " << type << " created!" 
						<< RESET << std::endl;
			return (this->_list[i]->clone());
		}
	}
	std::cout << RED << "==> Materia type " << type << " unknown" << RESET << std::endl;
	return NULL;
}
