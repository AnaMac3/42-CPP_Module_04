/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:03:21 by root              #+#    #+#             */
/*   Updated: 2025/09/16 11:33:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrpngCat_HPP
# define WrpngCat_HPP

# include "WrongAnimal.hpp"

# define RESET	"\033[0m"
# define YELLOW	"\033[33m"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
};

#endif
