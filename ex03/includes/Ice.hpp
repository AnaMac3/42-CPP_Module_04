/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:59:04 by root              #+#    #+#             */
/*   Updated: 2025/09/26 17:00:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define BLUE	"\033[34m"
# define RESET	"\033[0m"

/**
 * @class	Ice
 * @brief	Concrete materia of Ice type
 * 			- Inherits from AMateria 
 * 			- Implements clone() to return a heap-allocated copy of itself
 * 			- Implements use() to perform specific action
 * 
 * 			Ownership:
 * 			- clone() returns a new Cure* allocated on the heap; callers 
 * 			must delete it.
 */

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		void use(ICharacter& target);
		AMateria* clone() const; //??
};

#endif
