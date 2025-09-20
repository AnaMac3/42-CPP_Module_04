/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:34 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:32:40 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define BLUE 	"\033[34m"

/**
 * @class	Dog
 * @brief	Concrete class representing a dog.
 * 			- Inherits publicly from 'Animal'
 * 			- Overrides 'makeSound()'
 * AÑADIR INFO
 * 
 */

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound() const;
		void	setBrain(const Brain& brain);
		Brain&	getBrain() const; //not modify current object
};

#endif
