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


/**
 * @brief	Default destructor
 * 			- deletes all the materias in _inventory
 * 			- no deben intentar borrar materias que han sido unequiped
 */
Character::~Character()
{
	//std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i ++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

/**
 * @brief	Copy Constructor (deep copy)
 * 			IMPLEMENTACIÓN RECOMENDADA:
 * 				- Inicializar _inventory a nullptr
 * 				- copiar _name
 * 				- clonar inventorys -> por qué clonar ?? para no hacer shallow copy
 * 	por qué aquí no puedo utilizar directamente el asignment operator??
 */

Character::Character(const Character& other) : ICharacter(other),
												_inventory()
{
	//std::cout << "Character Copy Constructor called" << std::endl;
	//*this = other;
	this->_name = other._name;
	for (int i = 0; i < 4; i ++)
	{
		if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
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
	//std::cout << "Character Assignment Operator called" << std::endl
	if (this != &other)
	{
		this->_name = other._name;
		//*this->_inventory = *other._inventory; //solo copia el primer array de _inventory
		//si hay inventorys asignados, borrarlos
		for (int i; i < 4; i ++)
		{
			if (other._inventory[i])
				delete other._inventory[i];
		}
		for (int i; i < 4; i ++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone;
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
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
	//meten la Materia en el pprimer slot vacio del inventory que haya - de 0 a 3
	if (m)
	{
		for (int i = 0; i < 4; i ++)
		{
			if (this->_inventory[i] == m)
			{
				std::cout << "Materia " << m->getType() << " is already equipped to "
							<< this->_name << "'s inventory" << std::endl;
				return ;
			}
		}
		for(int i = 0; i < 4; i ++)
		{
			//y si no está, hacemos esto?: 
			if (this->_inventory[i] == NULL)
				this->_inventory[i] == m->clone();
			return ;
		}
		//if they try to add a materia to a full inventory -> nothing happens
		//if inventory is full
		std::cout << "Cannot equip materia, " << this->_name 
					<< "'s inventory is full" << std::endl;
	}
	else
		std::cout << "Invalid materia" << std::endl;
		
}

/**
 * @brief	Desequipa la materia en la posición idx sin borrarla
 * 			- If idx < 0 || idx >= 4 -> return (invalid index)
 * 			- If _inventory[idx] -> slot vacio, return
 * 			- Guardar el puntero en algún lado, pero no borrar
 * 			- Asignar _inventory[idx] a null
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
		std::cout << "Cannot unequip materia, invalid index" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Cannot unequio materia, empty slot" << std::endl;
		return ;
	}
	//guardar puntero en algun lugar (devolverlo o añadirlo a una lista suelo)
	//pero no borrarlo
	this->_inventory[idx] = NULL;
	std::cout << "Unequiped " << this->_inventory[idx]->getType()
				<< " from" << this->_name << "'s inventory at index "
				<< idx << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	//
}