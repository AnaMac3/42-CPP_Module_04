/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:25:18 by root              #+#    #+#             */
/*   Updated: 2025/09/20 17:22:47 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	
	std::cout << "Animal without const, for using setters: " << std::endl;
	Animal generic;
	generic.setType("Horse");
	generic.makeSound();
	std::cout << generic.getType() << " " << std::endl;

	std::cout << std::endl; 
	std::cout << "----------------------" << std::endl;

	std::cout << "Using Assignment operator in Cat: " << std::endl;
	Cat	cat1;
	Cat cat2;

	cat2 = cat1;
	cat2.makeSound(); //should be the same as cat1
	
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Wrong Animal: " << std::endl;

	WrongAnimal platypus;
	std::cout << platypus.getType() << std::endl;
	platypus.makeSound();

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Wrong Cat: " << std::endl;

	WrongCat bageera;
	std::cout << bageera.getType() << std::endl;
	bageera.makeSound();
	
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Using Copy Constructor: " << std::endl;
	WrongCat pink_panther(bageera);
	pink_panther.makeSound();

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	
	std::cout << "Deleting..." << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	
	return (0);
}