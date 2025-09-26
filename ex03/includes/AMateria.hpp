/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:51:46 by root              #+#    #+#             */
/*   Updated: 2025/09/26 12:50:22 by root             ###   ########.fr       */
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
 * @brief	Abstract class which represents a generic "materia".
 * 			This is the base class for the concrete types of materia (Ice, Cure).
 * 			Provies:
 * 			- A type identifier
 * 			- A clone interface to allow deep copies for runtime type
 * 			- A virtual method use() which aplies the efect upon a ICharacter
 * 
 * 			Properties:
 * 			- Ownership: the class doesn't free the materias pointed by others;
 * 			who creates a new AMateria must decide if transfers the ownership (?¿¿?)
 * 			- clone(): key method for implementing deep copy in classes with
 * 			pointers to AMateria
 * 			- Copy constructor and operator= are public to allow copies from
 * 			outside
 */

class AMateria
{
	protected:
		AMateria(); //para que no se creen instancias directamente de AMateria, las subclases pueden llamarlo. No es necesario (porque clone es pure virtual), pero da claridad y robustez

		std::string _type;

	public:
		AMateria(std::string const &type); //las subclases lo llaman para inicializar con su type

		AMateria(const AMateria& other); //copias y asignement: suelen ser public porque permiten copiar desde punteros o referencias a AMateria
		AMateria& operator=(const AMateria& other);

		virtual ~AMateria();

		std::string const &getType() const; //returns the materia type

		virtual AMateria* clone() const = 0; //pure virtual -> returns a pointer to a new instance of the same dynamic obj
		virtual void use(ICharacter& target); //uses interface...
};

#endif
