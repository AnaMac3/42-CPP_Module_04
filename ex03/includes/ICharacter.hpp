/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:43 by root              #+#    #+#             */
/*   Updated: 2025/09/26 10:21:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

//forward declaration 
class AMateria;

/**
 * @class	ICharacter
 * @brief	Interface abstracta que define la API pública de un personaje
 * 			(¿Qué es la API publica de un personaje)
 * 			- getter for name
 * 			- equip -...
 * 			- unequip
 * 			- use a materia on other character (a target)
 * 
 * 			Pure virtual -> la clase concreta debe implementar estos métodos
 * 
 * 			- Must have a virtual destructor to allow the delete through pointers
 * 			to the interface
 * 			- AQUÍ NO SE USA LA ORTODOX CANONICAL FORM PORQUE EN EL SUBJECT 
 * 			SE ESPECIFICA ESTA FORMA PARA LA CLASE ICHARACTER.
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
