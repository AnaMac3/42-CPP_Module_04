/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:48:14 by root              #+#    #+#             */
/*   Updated: 2025/09/26 16:52:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# define GREEN	"\033[32m"
# define RESET	"\033[0m"

/**
 * @class	Cure
 * @brief	Concrete AMateria representing the cure type
 * 			- Inherits from AMateria
 * 			- Implements clone() to return a heap-allocated copy of itself
 * 			- Implements use() to perform specific action
 * 
 * 			Ownership:
 * 			- clone() returns a new Cure* allocated on the heap; callers 
 * 			must delete it.
 */

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif
