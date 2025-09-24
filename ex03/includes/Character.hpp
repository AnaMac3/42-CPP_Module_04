#ifndef Character_HPP
# define Character_HPP

# include "AMateria.hpp"

/**
 * @class	Character
 * @brief	Cómo implemento la interfaz ICharacter?
 * 
 * 			POSEES AN INVENTORY OF 4 SLOTS -> AT MOST 4 MATERIAS.
 * 			IS EMPTY UPON CONSTRUCTION
 * 			THEY EQUIP THE MATERIAS IN THE FIRST EMPTY SLOT THEY FIND,
 * 			IN THE FOLLOWING ORDER: 
 * 			- FROM SLOT 0 TO SLOT 3
 * 			IF THEY TRY TO ADD A MATERIA TO A FULL INVENTORY, OR USE/UNEQUIO
 * 			A NON-EXISTENT MATERIA, NOTHING SHOULD HAPPEN (BUT BUGS ARE STILL FORBIDDEN)
 * 			THE UNEQUIP() MEMBER FUNCTION MUST NOT DELETE THE MATERIA
 * 
 * * 
 * 		use(int, ... -> use the Materia at the slot[idx] and pass the target parameter 
 * 					to the AMAteria::use function
 * 
 * 		Constructor taking its name as parameter
 * 		Copy (using copy constructor o copy assignment op) must be deep
 * 		During copy, the Materias of a Character must be deleted before the new ones
 * 		are added to their inventory
 * 		Materias must be deleted when a Character is destroyed
 */

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4]; //puntero a array de 4 objetos AMateria

	public:
		Character();
		Character(std::string const &name); //constructor con nombre
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		void	setName(std::string const &name);
		std::string const &getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target); 
};

#endif
