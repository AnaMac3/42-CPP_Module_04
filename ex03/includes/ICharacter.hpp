#ifndef ICharacter_HPP
# define ICharacter_HPP

# include "AMateria.hpp"

/**
 * @class	ICharacter
 * @brief	Interface
 * 		
 * 
 */

class ICharacter
{
	protected:
		ICharacter();
		ICharacter(ICharacter const &other); //NO SE SI LA INTERFAZ TIENE QUE TENER O NO ESTOS CONSTRUCTORES, AQUI O EN PUBLIC
		ICharacter& operator=(const ICharacter& other);

	public:
		virtual ~ICharacter();

		virtual std::string const &getName() const = 0;
		
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0; 
};

#endif
