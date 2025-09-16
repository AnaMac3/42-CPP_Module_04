/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:14 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:31:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrpngAnimau_HPP
# define WrpngAnimau_HPP

# include <iostream>

# define BG_YELLOW	"\033[43m"
# define CYAN		"\033[36m"
# define RESET		"\033[0m"

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);

		std::string const &getType() const;
		void	setType(const std::string &type);
		void	setSound(const std::string &sound);
		
		void	makeSound() const;
	
	protected:
		std::string _type;
		std::string _sound;
};

#endif
