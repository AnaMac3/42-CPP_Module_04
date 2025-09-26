/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:12:32 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:13:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

/**
 * @interface	IMateriaSource
 * @brief	Abstract interface for any class that can store and create Materias.
 * 			- Defines the API (Application Programming Interface) for storing
 * 			a template Materia (via learnMateria)
 * 			- Defines the API for generating new Materias by type 
 * 			(via createMateria)
 * 			- This interface ensures that concrete implementations like 
 * 			MateriaSource follow the required behaviour.
 * 
 */

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
