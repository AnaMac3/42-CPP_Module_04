/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:26:56 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:17:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define YELLOW	"\033[33m"
# define CYAN	"\033[36m" 	
# define RED	"\033[31m"
# define RESET	"\033[0m"

/**
 * @class	MateriaSource
 * @brief	Concrete implementation of IMateriaSource that can learn and
 * 			create Materias.
 * 			- Stores up to 4 "template" Materias (copies of those passed to
 * 			learnMateria)
 * 			- Creates a new Materias on demand by clonning the stored templates
 * 			via createMateria.
 * 
 * 			- Uses a fixed-size array of 4 pointers (_list) to store learned
 * 			Materias
 * 			- Owns the memory of stored Materias (closne); ensures proper
 * 			cleanup in destructor and assignment operator.
 * 
 * 			- Depends on AMateria (via pointers and clone() calls)
 * 			- Inherits from IMateriaSource to comply with the required 
 * 			interface
 * 
 */

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_list[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void	learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);	
};

#endif
