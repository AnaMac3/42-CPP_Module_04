#include "ICharacter.hpp"

/*ICharacter::ICharacter()
{

}

ICharacter::ICharacter(ICharacter const &other)
{
	*this = other;
}

ICharacter&	ICharacter::operator=(const ICharacter& other)
{
	if (this != &other)
	{
		//???
	}
	return (*this);
}*/

/**
 * @brief	Virtual destructor
 * 			- Pure virtual: must be implemented by the concrete class
 */

ICharacter::~ICharacter()
{
	//std::cout << "ICharacter Destructor called" << std::endl;
}

