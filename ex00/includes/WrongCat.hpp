/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:21 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:20:59 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrpngCat_HPP
# define WrpngCat_HPP

# include "WrongAnimal.hpp"

# define RESET	"\033[0m"
# define YELLOW	"\033[33m"
# define CYAN 	"\033[36m"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();

		virtual void	makeSound() const;
};

#endif
