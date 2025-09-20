/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:34 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:17:16 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define BLUE 	"\033[34m"

/**
 * @class	Dog
 * @brief	Concrete class representing a dog.
 * 			- Inherits publicly from 'Animal'
 * 			- Overrides 'makeSound()'
 * 
 */

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound() const;
};

#endif
