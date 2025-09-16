/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:51:34 by root              #+#    #+#             */
/*   Updated: 2025/09/16 15:43:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define RESET	"\033[0m"
# define GREEN	"\033[32m"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void	setBrain(const Brain& brain);
		Brain&	getBrain() const; //not modify current object

	private:
		Brain*	_brain;
};

#endif
