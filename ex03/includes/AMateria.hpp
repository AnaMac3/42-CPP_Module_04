/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:46 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:45:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# define BG_GREEN	"\033[42m"
# define RESET		"\033[0m"


/**
 * @class	AMateria
 * @brief	Abstract base class which representing a generic "materia".
 * 			Provides:
 * 			- A type identifier
 * 			- A polymorphic clone() method so that derived classes can be 
 * 			duplicated at runtime while preserving their dynamic type
 * 			- A virtual method use() method that derived classes override
 * 			to apply concrete effects to a character
 * 
 * 			Ownership and memory:
 * 			- AMateria itself does not take ownership of Materia pointers
 * 			passed to other parts of the program; it is the caller's
 * 			responsability to manage lifetime unless the pointer is 
 * 			explicity cloned and stored by a class (MateriaSource or
 * 			Character)
 * 			
 * 			- clone() is pure virtual; makes AMateria abstract (non-instantiable)
 * 			- Copy constructor and assignment operator are public to allow
 * 			explicit copying/cloning when needed
 * 			- The default constructor is protected to indicate AMateria is
 * 			intended to be a base class
 */

class AMateria
{
	protected:
		AMateria();

		std::string _type;

	public:
		AMateria(std::string const &type);

		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);

		virtual ~AMateria();

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
