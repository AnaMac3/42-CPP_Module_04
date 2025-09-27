/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:15:22 by amacarul          #+#    #+#             */
/*   Updated: 2025/09/27 10:25:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{   
	std::cout << "==============================" << std::endl;
	std::cout << "Create MateriaSource and learn materias" << std::endl;
	
	IMateriaSource* src = new MateriaSource(); //Constructor MateriaSource
	src->learnMateria(new Ice()); //Constructor AMateria - Ice + Ice clone -> Constructor AMateria - Copy Constructor Ice - Assignment operator Ice - AMateria
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(NULL); //Cannot learn NULL materias
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); //Cannot learn more materias (> 4)

	std::cout << std::endl;
	
	std::cout << "Create Character" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << std::endl;
	
	std::cout << "Create materias from MateriaSource" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	tmp = src->createMateria("cure");
	me->equip(tmp);

	//Try equip invalid materia
	me->equip(NULL); //Invalid materia

	//Full characters inventory
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp); //Inventory is full

	//Try create unkwon materia
	tmp = src->createMateria("stone"); //unknown

	std::cout << std::endl;

	//Other character
	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	//Unequip materias

	//Use materias
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	//Try use invalid index
	me->use(5, *bob); //invalid index

	//Try to use materias when character doesn't have them?
	bob->use(0, *me); //Slot 0 empty

	//Unequip
	me->unequip(0); //unequip Ice - no more Ice in the inventory
	me->unequip(1); //unequip Cure - there are more Cure

	//Try to use again
	me->use(0, *bob); //empty slot
	me->use(1, *bob); //empty slot
	

	std::cout << std::endl;

	//Free memory
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;

	return 0;
}