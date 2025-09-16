/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:04 by root              #+#    #+#             */
/*   Updated: 2025/09/16 15:52:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define BG_GREEN	"\033[42m"
# define BLUE		"\033[34m"
# define RESET		"\033[0m"

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);

		std::string const &getType() const;
		void	setType(const std::string &type);
		void	setSound(const std::string &sound);
		
		void	makeSound() const;

		virtual	Brain &getBrain(void) const = 0; //virtual: must be redefined by child classes, dinamic polimorfism
	
	protected:
		std::string _type;
		std::string _sound;
};

#endif
