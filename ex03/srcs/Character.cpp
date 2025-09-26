/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:34 by root              #+#    #+#             */
/*   Updated: 2025/09/26 17:21:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/**
 * @brief	Default constructor
 * 			- Initializes all inventory slots to NULL
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
 * 			- Initializes name to provided parameter
 * 			- Sets all inventory slots to NULL
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
 * 			- Initializes inventory to NULL
 * 			- Delegates to assignment operator to copy content
 * 
 * @param other	Character to copy from
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
 * 			- Deletes existing Materias in inventory
 * 			- Clones Materias from other into this inventory
 * 			- Copies character name
 * 
 * @param other	Character to assign from
 * @return Reference to this Character
 */

Character&	Character::operator=(const Character& other)
{
	std::cout << MAGENTA << "Character Assignment Operator called" 
				<< RESET << std::endl;

	if (this != &other)
	{
		this->_name = other.getName();
		for (int i = 0; i < 4; i ++)
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
 * 			- Deletes all the equiped materias in _inventory
 * 			- Iterates over _floor to delete unequipped Materias
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
	std::vector<AMateria*>::iterator it;
	for(it = _floor.begin(); it != _floor.end(); ++it)
		delete *it;
}

/**
 * @brief	Set the name for the Character
 * 
 * @param name	New name for the character
 */

void	Character::setName(std::string const &name)
{
	this->_name = name;
}

/**
 * @brief	Get the name of the Character
 * 
 * @return	Constant reference to name
 */

std::string const &Character::getName() const
{
	return (this->_name);
}

/**
 * @brief	Equip a Materia into the first free slot.
 * 			- Clones m to avoid shallow copy
 * 			- If no free slots, does nothing
 * 
 * 			- Ownership: the Character is responsible of the 'm' pointer,
 * 			except if it is later unequiped
 * 
 * @param m	Pointer to the Materia to equip
 */

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << RED << "==> Invalid materia" << RESET << std::endl;
		return ;
	}
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
	std::cout << RED <<  "==> Cannot equip materia, " << this->_name 
				<< "'s inventory is full" << RESET << std::endl;
}

/**
 * @brief	Unequip a Materia from given slot index without deleting
 * 			the AMateria
 * 
 * 			- If the index is invalid, returns
 * 			- If the slot is empty, returns
 * 			- Does not delete the Materia
 * 			- Stores pointer into _floor vector via push_back, for later cleanup
 * 			- Sets the slot to NULL
 * 			
 * 
 * @param idx	Slot index (0..3)
 * 
 */

void	Character::unequip(int idx)
{
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
	this->_floor.push_back(this->_inventory[idx]);
	std::cout << CYAN << "==> Unequiped " << this->_inventory[idx]->getType()
				<< " from " << this->_name << "'s inventory at index "
				<< idx << RESET << std::endl;
	this->_inventory[idx] = NULL;
}

/**
 * @brief	Use a Materia on a target
 * 			- If index invalid or slot empty, does nothing
 * 			- Otherwise delegates to AMateria::use
 * 
 * @param idx	Slot index (0..3)
 * @param target	Target character on which to apply the Materia
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
