/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:30:33 by root              #+#    #+#             */
/*   Updated: 2025/09/26 12:36:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/**
 * @brief	Default constructor
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
 * @brief	Name Constructor
 * 			DEBERIA INICIALIZAR CADA OBJETO DE AMATERIA (_INVENTORY) EN NULL?
 */

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << YELLOW << "MateriaSource Copy Constructor called" 
				<< RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_list[i] = NULL;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << YELLOW << "MateriaSource Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++) //borrar si hay materias en list en this
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

void	MateriaSource::learnMateria(AMateria *m)
{
	//copia la materia pasada como parámetro y la gurarda, para poder clonarla después
	//si ya hay 4 elementos, mensaje de que no se puede aprender más
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

AMateria* MateriaSource::createMateria(std::string const &type)
{
	//devuelve new raw materia
	//el ultimo es una copia del materia previamente aprendido
	//por materiasource, cuyo type equivale al type pasado como parámetro
	//devuelve 0 si el type es desconocido
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
	return NULL; //devuelve 0 si el type es desconocido
}
