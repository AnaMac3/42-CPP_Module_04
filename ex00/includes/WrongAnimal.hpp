/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:14 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:21:10 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrpngAnimau_HPP
# define WrpngAnimau_HPP

# include <iostream>

# define BG_YELLOW	"\033[43m"
# define BG_CYAN	"\033[46m"
# define RESET		"\033[0m"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		std::string const &getType() const;
		void	setType(const std::string &type);
		void	setSound(const std::string &sound);
		
		virtual void	makeSound() const;
	
	protected:
		std::string _type;
};

#endif
