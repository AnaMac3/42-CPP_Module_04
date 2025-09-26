/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:43 by root              #+#    #+#             */
/*   Updated: 2025/09/26 17:05:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

//forward declaration 
class AMateria;

/**
 * @class	ICharacter
 * @brief	Abstract interface that defines the public API (Application
 * 			Programming Interface) of a character.
 * 			- Provides a getter for the character's name
 * 			- Allow equipping and unequipping Materias
 * 			- Allow using a Materia on a target character
 * 
 * 			- Pure virtual methods: every concrete subclass must implement
 * 			them.
 * 			- A virtual destructor is mandatory: deleting through an 
 * 			ICharacter pointer must correctly invoke the derived class
 * 			destructor
 * 
 */

class ICharacter
{
	public:
		virtual ~ICharacter() {} 

		virtual std::string const &getName() const = 0;
		
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0; 
};

#endif
