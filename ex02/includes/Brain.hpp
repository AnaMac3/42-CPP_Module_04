/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:51:36 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:40:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <algorithm>
# include <string>

# define BG_MAGENTA	"\033[45m"
# define RESET		"\033[0m"

/*array of 100 std::string called ideas

Dog y Cat tendrán un atributo privado llamado Brain*
En su construcción, dog y cat crearan su Brain con new Brain()
En la destrucción, dog y cat delete su brain
*/

/**
 * @class	Brain
 * @brief	Represents the brain of an animal, storing up to 100 ideas.
 * 			- Manages an array of 100 std::string ideas
 * 			- Provides getter and setter for ideas by index
 * 			- Copy is supported (deep copy of all ideas) by the overload of 
 * 			= operator
 */

class Brain
{
	private:
		std::string _ideas[100];
		//std::array<std::string, 100> _ideas; //container class

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		std::string const	&getIdea(int const &index) const;
		void	setIdea(std::string const &idea, int const &index);

};

#endif
