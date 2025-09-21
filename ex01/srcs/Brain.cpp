/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:54:52 by root              #+#    #+#             */
/*   Updated: 2025/09/21 17:40:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * @brief	Default constructor
 * 
 */

Brain::Brain()
{
	std::cout << BG_MAGENTA << "Brain Default Constructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Copy constructor
 * 
 * @param other	Another Brain object to copy from.
 */

Brain::Brain(const Brain& other)
{
	std::cout << BG_MAGENTA <<  "Brain Copy Constructor called" 
				<< RESET << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator.
 * 			Performs a deep copy of the ideas array
 * 			
 * 			std::copy(InputIt first, InputIt last, OutputIt d_first);
 * 
 * @param other	Another Brain object to assign from.
 * @return	Reference to the current object
 */

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << BG_MAGENTA << "Brain Assignment Operator called" 
				<< RESET << std::endl;
	if (this != &other)
	{
		std::copy(other._ideas, other._ideas + 100, this->_ideas);
		//_ideas=other._ideas // if std::array<std::string, 100> _ideas; bc std::array has operator= overloaded
	}
	return (*this);
}

/**
 * @brief	Destructor
 * 
 */

Brain::~Brain()
{
	std::cout << BG_MAGENTA << "Brain Destructor called" 
				<< RESET << std::endl;
}

/**
 * @brief	Gets an idea at a given index.
 * 
 * @param index		Index of the idea (0-99)
 * @return	Constant reference to the idea if index is valid, otherwise
 * 			a reference to an empty string.
 */
std::string const	&Brain::getIdea(int const &index) const
{
	static std::string empty = "";

	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return(empty);
}

/**
 * @brief	Sets an idea at a given index
 * 
 * @param idea	The new idea to store
 * @param index	Index in the array (0-99). Ignored if out of the range
 */

void	Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}
