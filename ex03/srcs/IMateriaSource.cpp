#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource Default Constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	//std::cout << "IMateriaSource Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	std::cout << "IMateriaSource Copy Constructor called" << std::endl;
	*this = other;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& other)
{
	std::cout << "IMateriaSource Assignment Operator called" << std::endl;
	if (this != &other)
	{
		//copy atributes
	}
	return (*this);
}
