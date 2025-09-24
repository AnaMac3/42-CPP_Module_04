#ifndef ICharacter_HPP
# define ICharacter_HPP

# include "AMateria.hpp"

/**
 * @class	ICharacter
 * @brief	Interface abstracta que define la API pública de un personaje
 * 			(¿Qué es la API publica de un personaje)
 * 			- getter for name
 * 			- equip -...
 * 			- unequip
 * 			- use a materia on other character (a target)
 * 
 * 			Pure virtual -> la clase concreta debe implementar estos métodos
 * 
 * 			- Must have a virtual destructor to allow the delete through pointers
 * 			to the interface
 * 			- NO SE SI ME SOBRAN LOS CONSTRUCTORES DEFAULT/COPY... MIRAR NORMAS...
 * 			EN EL EJERCICIO NO SE PIDEN, PUEDO PRESCINDIR TB DEL OPERADOR??
 * 
 */

class ICharacter
{
	/*protected:
		ICharacter();
		ICharacter(ICharacter const &other); //NO SE SI LA INTERFAZ TIENE QUE TENER O NO ESTOS CONSTRUCTORES, AQUI O EN PUBLIC
		ICharacter& operator=(const ICharacter& other);
	*/
	public:
		virtual ~ICharacter();

		virtual std::string const &getName() const = 0;
		
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0; 
};

#endif
