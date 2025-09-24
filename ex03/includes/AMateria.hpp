#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>

/**
 * @class	AMateria
 * @brief	Abstract class
 * 			
 */

class AMateria
{
	protected:
		AMateria();

		std::string _type;

	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);

		std::string const &getType() const; //returns the materia type

		virtual AMateria* clone() const = 0; //pure virtual
		virtual void use(ICharacter& target); //uses interface...
};

#endif
