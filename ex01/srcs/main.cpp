/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:25:18 by root              #+#    #+#             */
/*   Updated: 2025/09/27 10:17:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int	main()
{
	std::cout << "======================================================" << std::endl;
	std::cout << "Create an array of pointers to Animal objects: 5 Dogs and 5 Cats." << std::endl;
	const Animal* pets[10]; // Constructor - Animal
	
	for (int i = 0; i < 10; i ++)
	{
		if (i < 10 / 2)
			pets[i] = new Dog(); // Constructor - Animal - Dog - Brain * 5
		else
			pets[i] = new Cat(); // Constructor - Animal - Cat - Brain * 5
	}

	std::cout << "\nCheck types:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal num " << i << " is " 
					<< pets[i]->getType() << " type. " << std::endl;
	}

	std::cout << std::endl;

	std::cout << "======================================================" << std::endl;

	std::cout << "Use Brains:" << std::endl;
	
	pets[0]->getBrain().setIdea("I am a Dog.", 0);
	pets[0]->getBrain().setIdea("I am hungry.", 1);
	pets[0]->getBrain().setIdea("I want to go for a walk.", 2);

	std::cout << "pets[0] is type " << pets[0]->getType()
				<< " and its idea 0 is: "
				<< pets[0]->getBrain().getIdea(0) << std::endl;
	std::cout << "pets[0] is type " << pets[0]->getType()
				<< " and its idea 1 is: " 
				<< pets[0]->getBrain().getIdea(1) << std::endl;
	std::cout << "pets[0] is type " << pets[0]->getType()
				<< " and its idea 2 is: " 
				<< pets[0]->getBrain().getIdea(2) << std::endl;
	std::cout << "pets[1] is type " << pets[1]->getType()
				<< " and its idea 2 is: " 
				<< pets[1]->getBrain().getIdea(0) << std::endl; //empty
	
	std::cout << std::endl;
	std::cout << "======================================================" << std::endl;

	std::cout << "Assign Brain to pets[5] and test deep copy: " << std::endl;
	Brain brain1; // Constructor - Brain
	
	brain1.setIdea("I have a brain.", 0);
	brain1.setIdea("Do I have a body?", 1);
	for(int i = 2; i < 7; i ++)
		brain1.setIdea("I am bored...", i);
	brain1.setIdea("Bye!!", 7);
	
	pets[5]->getBrain() = brain1; // Assignment operator - Brain

	std::cout << "\npets[5] ideas after assignment: " << std::endl;
	for(int i = 0; i < 8; i ++)
	{
		std::cout << "Idea num " << i << ": "
					<< pets[5]->getBrain().getIdea(i) << std::endl;
	}
	
	std::cout << "\nModify brain1 and check that pets[5] did not change: " << std::endl;
	
	brain1.setIdea("I changed my mind!", 0);
	std::cout << "brain1 idea 0 now is: " << brain1.getIdea(0) << std::endl;
	std::cout << "pets[5] idea 0 still: " << pets[5]->getBrain().getIdea(0) << std::endl;
	
	std::cout << std::endl;
	std::cout << "======================================================" << std::endl;
	
	std::cout << "Check deep copy with stack objects:" << std::endl;
	std::cout << "1. With assignment operator: \n" << std::endl;
	Dog dog1; // Constructor Dog - Brain - Animal
	Dog dog2; // Constructor Dog - Brain - Animal

	dog1.getBrain().setIdea("I am a dog.", 0);
	
	dog2 = dog1; // Assignment operator - Dog - Animal + delete Brain + Constructor Brain + Assignment operator Brain
	
	std::cout << "dog2 idea 0 is (a copy of dog1): " 
				<< dog2.getBrain().getIdea(0) << std::endl;
	
	dog2.getBrain().setIdea("I am a wolf now!!", 0);
	
	std::cout << "Now, dog2 idea 0 is: " 
				<< dog2.getBrain().getIdea(0) << std::endl;

	std::cout << "dog1 idea 0 still: "
				<< dog1.getBrain().getIdea(0) << std::endl;

	std::cout << "\n2. With copy constructor: \n" << std::endl;
	Dog dog3(dog2); // Animal Copy Constructor - Assignment operator + Brain Copy - Assignment + Dog constructor

	std::cout << "dog3 idea 0 is (a copy of dog2): "
				<< dog3.getBrain().getIdea(0) << std::endl;
	
	dog3.getBrain().setIdea("I wanna be a butterfly...", 1);
	
	std::cout << "dog3 idea 1 is: "
				<< dog3.getBrain().getIdea(1) << std::endl;
	
	std::cout << "dog2 idea 1 still: "
				<< dog2.getBrain().getIdea(1) << std::endl; //empty
	
				
	std::cout << std::endl;
	std::cout << "======================================================" << std::endl;

	std::cout << "Check deep copy with heap objects:" << std::endl;
	
	Cat* heapCat = new Cat(); // Constructor Animal - Cat - Brain
	
	heapCat->getBrain().setIdea("I am a Cat in the Heap.", 0);

	Cat* secondCat = new Cat(*heapCat); // Animal Copy Constructor - Assignment + Brain Copy - Assignment + Cat Copy

	std::cout << "secondCat's idea after the copy: "
				<< secondCat->getBrain().getIdea(0) << std::endl;
	
	secondCat->getBrain().setIdea("MIAAAAAAU", 0);
	std::cout << "secondCat's idea after changing it: "
				<< secondCat->getBrain().getIdea(0) << std::endl;
	
	std::cout << std::endl;
	std::cout << "======================================================" << std::endl;	
	std::cout << "Delete Animal objects: " << std::endl;
	for (int i = 0; i < 10; i++)
		delete(pets[i]); //Destructor Dog - Brain - Animal * 5 + Cat - Brain - Animal * 5
	
	std::cout << std::endl;

	std::cout << "Delete heap cats: " << std::endl;
	delete (heapCat); // Destructor Cat - Brain - Animal
	delete (secondCat); // Destructor Cat - Brain - Animal

	std::cout << std::endl;
	std::cout << "Automatic deletes: " << std::endl;
	//Dog (dog1)
	//Dog (dog2)
	//Dog (dog3) 
		
	return (0);
}
