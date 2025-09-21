/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:04 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:49:33 by root             ###   ########.fr       */
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
 * 			derive from. 
 * 			- Stores the type of the animal as a string
 * 			- Provieds a virtual interface for making sounds
 * 			- Declares a pure virtual method getBrain() that forces derived
 * 			classes to implement Brain access.
 * 			
 * 			ANIMAL NO TIENE BRAIN. GETBRAIN() TIENE QUE ESTAR EN ANIMAL
 * 			PORQUE SI NO NO PODRIA ACCEDER AL BRAIN DEL ARRAY DE PUNTEROS A ANIMAL
 * 			DEL MAIN QUE DA EL EJERCICIO. POR LO QUE GETBRAIN TIENE QUE SER 
 * 			UN PURE VIRTUAL METHOD, POR LO QUE ANIMAL ES UNA CLASE ABSTRACTA
 * 	
 * 			- This class cannot be instantiated directly due to the pure 
 * 			virtual method
 * 			- Derived classes must manage their own Brain allocation and
 * 			deallocation.
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
		virtual	Brain &getBrain(void) const = 0;
};

#endif
