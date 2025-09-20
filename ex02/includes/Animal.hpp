/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:04 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:36:59 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define BG_GREEN	"\033[42m"
# define BG_BLUE	"\033[44m"
# define RESET		"\033[0m"

class Animal
{
	protected:
		std::string _type;

		Animal();
		Animal(const Animal& other);
		
	public:
		Animal& operator=(const Animal& other); //deberia quedarse público??
		virtual ~Animal();

		std::string const &getType() const;
		void	setType(const std::string &type);
		
		virtual void	makeSound() const;
		virtual	Brain &getBrain(void) const = 0; //virtual: must be redefined by child classes, dinamic polimorfism
	
	
};

#endif
