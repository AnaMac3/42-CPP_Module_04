/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:26:56 by root              #+#    #+#             */
/*   Updated: 2025/09/26 13:04:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define YELLOW	"\033[33m"
# define CYAN	"\033[36m" 	
# define RED	"\033[31m"
# define RESET	"\033[0m"

/**
 * @class	MateriaSource
 * @brief	
 * 			learnMateria(AMateria*) copia la Materia pasada como parametro
 * 		y la guarda en memoria para poder clonarla después. COmo Character, MateriaSource
 * 		puede guardar hasa 4 Materias. No son necesariamente únicas.
 * 		-...
 * 		learnMateria: se le pasan materias y las guarda
 * 		createMateria: se busca si ya se ha aprendido esa materia y devuelve
 * 		un nuevo objeto clonado
 * 		si no conoce ese tipo, devuelve nullptr
 * 		MateriaSource almacena templates (clones) para poder fabricar nuevos
 * 		objetos idénticos cuando se soliciten.
 * 
 */

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_list[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void	learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);	
};

#endif
