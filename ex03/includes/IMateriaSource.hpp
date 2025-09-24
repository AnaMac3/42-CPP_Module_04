#ifndef IMateriaSpurce_HPP
# define IMateriaSpurce_HPP

# include <iostream>
# include "AMateria.hpp"

/**
 * learnMateria(AMateria*) -> copia la Materia pasada como parametro y la guarda
 * en memoria para que pueda ser clonada después. Como Character, MateriaSource puede saber
 * hasta 4 Materias. No tienen por qué ser necesariamente unique
 * createMateria(std::string const &) -> devuelve un nuew Materia. The latter is a copy of
 * the Materia previously learned by MateriaSource whose type equals the one passed as parameter
 * Returns 0 if the type is unknown
 * 
 * In a nutshell your MateriaSource must be able to learn "templates" of Materias to create them
 * when needed. Then, you will be able to generate a new Materia using just a string
 * that identifies its type
 */

class IMateriaSource
{
	public:
		//IMateriaSource();
		virtual ~IMateriaSource();
		//IMateriaSource(const IMateriaSource& other);
		//IMateriaSource& operator=(const IMateriaSource& other);

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
