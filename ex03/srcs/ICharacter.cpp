#include "ICharacter.hpp"

ICharacter::ICharacter()
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
}

ICharacter::~ICharacter()
{
	//std::cout << "ICharacter Destructor called" << std::endl;
}

