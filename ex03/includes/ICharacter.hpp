#ifndef ICharacter_HPP
# define ICharacter_HPP

# include <iostream>
# include "AMateria.hpp"

/**
 * @class	ICharacter
 * @brief	Interface
 * 			POSEES AN INVENTORY OF 4 SLOTS -> AT MOST 4 MATERIAS.
 * 			IS EMPTY UPON CONSTRUCTION
 * 			THEY EQUIP THE MATERIAS IN THE FIRST EMPTY SLOT THEY FIND,
 * 			IN THE FOLLOWING ORDER: 
 * 			- FROM SLOT 0 TO SLOT 3
 * 			IF THEY TRY TO ADD A MATERIA TO A FULL INVENTORY, OR USE/UNEQUIO
 * 			A NON-EXISTENT MATERIA, NOTHING SHOULD HAPPEN (BUT BUGS ARE STILL FORBIDDEN)
 * 			THE UNEQUIP() MEMBER FUNCTION MUST NOT DELETE THE MATERIA
 * 
 * 		Dónde indico todo esto si el ICharacter tiene todos los métodos virtuales puros?
 * 
 * 		use(int, ... -> use the Materia at the slot[idx] and pass the target parameter 
 * 					to the AMAteria::use function
 * 
 * 		Constructor taking its name as parameter
 * 		Copy (using copy constructor o copy assignment op) must be deep
 * 		During copy, the Materias of a Character must be deleted before the new ones
 * 		are added to their inventory
 * 		Materias must be deleted when a Character is destroyed
 * 
 */

class ICharacter
{
	public:
		virtual ~ICharacter();

		virtual std::string const &getName() const = 0;
		
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0; 
};

#endif
