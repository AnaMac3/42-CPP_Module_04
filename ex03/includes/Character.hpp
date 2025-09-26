/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:39 by root              #+#    #+#             */
/*   Updated: 2025/09/26 17:11:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
# define Character_HPP

# include <vector>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m" 		
# define RED		"\033[31m"
# define RESET		"\033[0m"

/**
 * @class	Character
 * @brief	Concrete implementatio of ICharacter with a fixed-size inventory
 * 			- _inventory contains 4 slots initialized to NULL
 * 			- equip(m) places a clone of m in the first available slot of
 * 			_inventory
 * 			- unequip(idx) removes the pointer from the inventory slot
 * 			without deleting it; the pointer is stored in _floor dynamic
 * 			vector to preserve the ownership
 * 			- use(idx, target) invokes the AMateria::use function of the 
 * 			Materia in the given slot, passing target as argument
 * 
 * 			Memmory management:
 * 			- Destructor deletes all equipped Materias
 * 			- Destructor also frees unequiped Materias stored in _floor
 * 			- Copy constructor and assignment operator perform deep copies
 * 			
 * 			Dependencies:
 * 			- Depends on AMateria (for inventory and floor storage)
 * 			- Depends on ICharacter (to implement use delegation)
 *
 */

class Character : public ICharacter
{
	private:
		std::string	_name; 
		AMateria	*_inventory[4];
		std::vector<AMateria*> _floor;

	public:
		Character();
		Character(std::string const &name);
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
