/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:51:36 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:34:05 by amacarul         ###   ########.fr       */
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

class Brain
{
	private:
		std::string _ideas[100];
		//std::array<std::string, 100> _ideas;

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		std::string const	&getIdea(int const &index) const;
		void	setIdea(std::string const &idea, int const &index);

};

#endif
