#include "Character.hpp"

Character::Character() : _name("default"),
						_inventory()
{
	//std::cout << "Character Default Constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name),
												_inventory()
{

}

Character::~Character()
{
	//std::cout << "Character Destructor called" << std::endl;
}

Character::Character(const Character& other)
{
	//std::cout << "Character Copy Constructor called" << std::endl;
	*this = other;
}

Character&	Character::operator=(const Character& other)
{
	//std::cout << "Character Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		*this->_inventory = *other._inventory; //deep copy of inventory
	}
	return (*this);
}

void	Character::setName(std::string const &name)
{
	this->_name = name;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	//meten la Materia en el pprimer slot vacio del inventory que haya - de 0 a 3
	if (m)
	{
		for(int i = 0; i < 3; i ++)
		{
			//si ya está en el inventario, clonamos?
			//y si no está, hacemos esto?: 
			if (this->_inventory[i] == NULL)
				this->_inventory[i] == m;
			return ;
		}
		//if they try to add a materia to a full inventory -> nothing happens
		//if inventory is full
		std::cout << "Cannot equip materia " << this->_name 
					<< "'s inventory is full" << std::endl;
	}
	else
		
}

void	Character::unequip(int idx)
{
	//must not delete the materia
	//if they use/unequip a non-existent materia -> nothing happens
}

void	Character::use(int idx, ICharacter& target)
{
	//
}