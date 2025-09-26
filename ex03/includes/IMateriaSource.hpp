/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:12:32 by root              #+#    #+#             */
/*   Updated: 2025/09/26 13:05:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

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
 * 
 * NO SE PONEN LOS CONSTRUCTORES PORQUE EL SUBJECT DA LA FORMA DE IMATERIASOURCE
 */

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
