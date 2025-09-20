/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:54:52 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:33:43 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BG_MAGENTA << "Brain Default Constructor called" 
				<< RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << BG_MAGENTA <<  "Brain Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << BG_MAGENTA << "Brain Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		/*for (int i = 0; i < 100; i ++)
			this->_ideas[i] = ohter._ideas[i];*/
		//alternativa: std::copy de algorithm
		//std::copy(InputIt first, InputIt last, OutputIt d_first)
		std::copy(other._ideas, other._ideas + 100, this->_ideas);
		//si _ideas fuera un std::array<std::string, 100> sí podríamos hacer _ideas=other._ideas, porque std::array tiene operador= sobrecargado
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << BG_MAGENTA << "Brain Destructor called" 
				<< RESET << std::endl;
}

std::string const	&Brain::getIdea(int const &index) const
{
	static std::string empty = "";

	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return(empty);
}

void	Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}
