/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:04 by root              #+#    #+#             */
/*   Updated: 2025/09/24 11:42:04 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define BG_GREEN	"\033[42m"
# define BG_BLUE	"\033[44m"
# define RESET		"\033[0m"

/**
 * @class Animal
 * @brief	Designed as polymorphic base class that other specific animals will
 * 			derive from. Abstract (not instantiable) because it declares at least
 * 			one pure virtual method.
 * 
 * 			- Stores the type of the animal as a string
 * 			- Provides a virtual interface for making sounds
 * 			- Declares a pure virtual method getBrain() so that derived classes
 * 			must implement access to ther Brain.
 * 			- The constructor is protected, which adds an extra restriction
 * 			(prevents instantiation even if there were no pure virtuals).
 * 			- The overloaded operator = and the copy constructor mustn't be
 * 			protected because the derived classes could need them.
 * 			- The destructor must be public and virtual:
 * 				- Public: so polymorphic deletion (delete basePtr) is allowed
 * 				- Virtual: so the correct derived destructor is called
 * 			
 * 			Note: Animal itself does not own Brain, but getBrain() must be 
 * 			declared in the base class to allow Brain access through a pointer
 * 			to Animal (e.g., in an array of Animal* in main)
 * 	
 * 			- This class cannot be instantiated directly
 * 			- Derived classes are responsible for Brain allocation and deallocation.
 * 
 */

class Animal
{
	protected:
		Animal();
		
		std::string _type;

	public:
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string const &getType() const;
		void	setType(const std::string &type);
		
		virtual void	makeSound() const;
		virtual	Brain &getBrain(void) const = 0; //virtual pure

};

#endif
