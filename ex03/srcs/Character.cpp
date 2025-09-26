/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:34 by root              #+#    #+#             */
/*   Updated: 2025/09/26 12:35:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/**
 * @brief	Default constructor
 * 
 */

Character::Character() : _name("default")
{
	std::cout << MAGENTA << "Character Default Constructor called" 
				<< RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

/**
 * @brief	Name Constructor
 * 			DEBERIA INICIALIZAR CADA OBJETO DE AMATERIA (_INVENTORY) EN NULL?
 */

Character::Character(std::string const &name) : _name(name)
{
	std::cout << MAGENTA << "Character Name Constructor called" 
				<< RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}


/**
 * @brief	Copy Constructor (deep copy)
 * 			IMPLEMENTACIÓN RECOMENDADA:
 * 				- Inicializar _inventory a nullptr
 * 				- copiar _name
 * 				- clonar inventorys -> por qué clonar ?? para no hacer shallow copy
 * 	por qué aquí no puedo utilizar directamente el asignment operator??
 */

Character::Character(const Character& other)
{
	std::cout << MAGENTA << "Character Copy Constructor called" 
				<< RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = other;
}

/**
 * @brief	Assignment operator
 * 			- IMPLEMENTACIÓN RECOMENDADA:
 * 			- si this y other no son iguales, seguir
 * 			- copiar _name
 * 			- si hay AMateria en los inventarios, deletearlos
 * 			- cclonarlos
 * 
 * @param other
 * @return Reference to the current object
 */

Character&	Character::operator=(const Character& other)
{
	std::cout << MAGENTA << "Character Assignment Operator called" 
				<< RESET << std::endl;

	if (this != &other)
	{
		this->_name = other.getName();
		for (int i = 0; i < 4; i ++) //si el Character actual tiene AMaterias en el inventario, borrarlos
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

/**
 * @brief	Default destructor
 * 			- deletes all the equiped materias in _inventory
 * 			- debe liberar las materias unequiped que están en _floor
 */

Character::~Character()
{
	std::cout << MAGENTA << "Character Destructor called" 
				<< RESET << std::endl;

	for (int i = 0; i < 4; i ++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	//iterar _floor para liberar las materias unequipadas
	std::vector<AMateria*>::iterator it; //qué es esto??
	for(it = _floor.begin(); it != _floor.end(); ++it) //explicar lógica
	{
		delete *it;
	}
	
}

/**
 * @brief	Set the name for the Character
 * 
 * @param name	New name
 */

void	Character::setName(std::string const &name)
{
	this->_name = name;
}

/**
 * @brief	Get the name of the Character
 * 
 * @return	Reference to constant name
 */

std::string const &Character::getName() const
{
	return (this->_name);
}

/**
 * @brief	Equipa la materia 'm' en el primer slot vacío
 * 			- Si no hay m, no hace nada
 * 			- Si m ya está en el inventario (comparación de punteros),
 * 			return (evita duplicar)	
 * 			- Si m no está en el inventario, y tenemos un slot vacio,
 * 			lo clonamos en el primer slot vacio
 * 			- Si se termina el bucle (inventario lleno) -> no hace nada
 * 
 * 			- Ownership: the Character is responsible of the 'm' pointer,
 * 			except if it is later unequiped
 */

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << RED << "==> Invalid materia" << RESET << std::endl;
		return ;
	}
	//meten la Materia en el pprimer slot vacio del inventory que haya - de 0 a 3
	for (int i = 0; i < 4; i ++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			std::cout << CYAN << "==> " << this->_name << " equiped with " 
						<< m->getType() << " materia in slot " << i 
						<< RESET << std::endl;
			return ;
		}
	}	
	//if inventory is full -> nothing happens
	std::cout << RED <<  "==> Cannot equip materia, " << this->_name 
				<< "'s inventory is full" << RESET << std::endl;
}

/**
 * @brief	Desequipa la materia en la posición idx sin borrarla
 * 			- If idx < 0 || idx >= 4 -> return (invalid index)
 * 			- If _inventory[idx] -> slot vacio, return
 * 			- Guardar el puntero en algún lado, pero no borrar
 * 			- Asignar _inventory[idx] a null
 * 			
 * 			El subject exige que no se haga delete aquí
 * 
 * @param idx	Slot index (0...3)
 * 
 */

void	Character::unequip(int idx)
{
	//must not delete the materia
	//if they use/unequip a non-existent materia -> nothing happens
	if (idx < 0 || idx >= 4)
	{
		std::cout << RED << "==> Cannot unequip materia, invalid index" 
					<< RESET << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << RED << "==> Cannot unequip materia, slot " << idx << " is empty"
					<< RESET << std::endl;
		return ;
	}
	//guardar puntero en algun lugar (devolverlo o añadirlo a una lista suelo)
	//pero no borrarlo!! 
	this->_floor.push_back(this->_inventory[idx]); //guardar puntero
	std::cout << CYAN << "==> Unequiped " << this->_inventory[idx]->getType()
				<< " from " << this->_name << "'s inventory at index "
				<< idx << RESET << std::endl;
	this->_inventory[idx] = NULL;
}

/**
 * @brief 
 * 
 * @param idx
 * @param target
 */

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << RED << "==> Cannot use materia, invalid index" 
					<< RESET << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << RED << "==> Cannot use materia, slot " << idx << " is empty"
					<< RESET << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}