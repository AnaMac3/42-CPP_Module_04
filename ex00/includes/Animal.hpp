/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:04 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:24:43 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define BG_GREEN	"\033[42m"
# define BG_BLUE	"\033[44m"
# define RESET		"\033[0m"

/**
 * @class	Animal
 * @brief	Designed as polymorphic base class that other specific animals will
 * 			derive from. 
 * 			- '_type' is declared as protected to allow derived classes to access
 * 			and modify it directly.
 * 			- 'getType()' returns a const reference to avoid unnecessary copies
 * 			and to ensures the caller cannot modify the internal state directly
 * 			- 'setType()' accepts a const std::string& for efficiency (avoids
 * 			copying arguments)
 * 			- The destructor is declared virtual to ensure proper destruction
 * 			of derived objects when deleted through a pointer to 'Animal'
 * 			- 'makeSound()' is a virtual function so that each subclass can
 * 			override it with its own specific sound. It is also marked const since
 * 			calling it does not alter the object state.
 * 
 */

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string const &getType() const;
		void	setType(const std::string &type);
		
		virtual void	makeSound() const;

};

#endif
