/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:22 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:28:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define BLUE 	"\033[34m"

/**
 * @class	Cat
 * @brief	Concrete class representing a cat.
 * 			- Inherits publicly from 'Animal'.
 * 			- Overrides 'makeSound()'
 *			- Owns a Brain instance (allocated dynamically)
 * 			- Provides Brain access ('setBrain()' and 'getBrain()')
 * 
 */

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
		void	setBrain(const Brain& brain);
		Brain&	getBrain() const; //not modify current object
};

#endif
