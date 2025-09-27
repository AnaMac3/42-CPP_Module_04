/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:25:18 by root              #+#    #+#             */
/*   Updated: 2025/09/27 09:54:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal(); //Constructor - Animal
	const Animal* j = new Dog(); // Constructor - Animal - Dog
	const Animal* i = new Cat(); // Constructor - Animal - Cat

	std::cout << j->getType() << " " << std::endl; // Dog
	std::cout << i->getType() << " " << std::endl; // Cat
	
	std::cout << std::endl;

	meta->makeSound(); // makeSound Animal
	i->makeSound(); // makeSound Cat
	j->makeSound(); //makeSound Dog
	

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	
	std::cout << "Animal without const, for using setters: " << std::endl;
	Animal generic; // Constructor - Animal
	generic.setType("Horse"); 
	generic.makeSound(); // makeSound Animal
	std::cout << generic.getType() << " " << std::endl; // Horse

	std::cout << std::endl; 
	std::cout << "----------------------" << std::endl;

	std::cout << "Using Assignment operator in Cat: " << std::endl;
	Cat	cat1; // Constructor Animal - Cat
	Cat cat2; // Constructor Animal - Cay

	cat2 = cat1; // Asignment operator - Cat - Animal
	cat2.makeSound(); //makeSound Cat
	
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Wrong Animal: " << std::endl;

	WrongAnimal platypus; // Constructor WrongAnimal
	std::cout << platypus.getType() << std::endl; // Wrong Default
	platypus.makeSound(); // makeSound WrongAnimal

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Wrong Cat: " << std::endl;

	WrongCat bageera; // Constructor WrongAnimal - WrongCat
	std::cout << bageera.getType() << std::endl; // WrongCat
	bageera.makeSound(); // makeSound WrongCat
	
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "Using Copy Constructor: " << std::endl;
	WrongCat pink_panther(bageera); // Copy Constructor - WrongAnimal - WrongCat
	pink_panther.makeSound(); // makeSound WrongCat

	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	
	std::cout << "Deleting..." << std::endl;
	delete meta; //Destructor - Animal
	delete i; // Destructor Cat - Animal
	delete j; // Destructor Dog - Animal

	std::cout << std::endl;

	std::cout << "----------------------" << std::endl;
	
	std::cout << "Automatic Deletes: " << std::endl;
	
	// Destructor - Animal (generic)
	// Destructor - Cat - Animal (cat1)
	// Destructor - Cat - Animal (cat2)
	// Destructor - WrongAnimal (platypus)
	// Destructor - WrongCat - WrongAnimal (bageera)
	// Destructor - WrongCat - WrongAnimal (pink_panther)
	
	return (0);
}