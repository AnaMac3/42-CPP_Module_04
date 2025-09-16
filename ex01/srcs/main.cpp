/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:25:18 by root              #+#    #+#             */
/*   Updated: 2025/09/16 16:43:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int	main()
{
	//Create an array of Animal objects, where half are Dog objects and the other half are Cat objects
	std::cout << "Create an array of Animal objects: 5 Dogs and 5 Cats." << std::endl;
	const Animal* pets[10];
	
	for (int i = 0; i < 10; i ++)
	{
		if (i < 10 / 2)
			pets[i] = new Dog();
		else
			pets[i] = new Cat();
	}

	std::cout << std::endl;

	std::cout << "Check types:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal num " << i << " is " 
					<< pets[i]->getType() << " type. " << std::endl;
	}

	std::cout << std::endl;
	
	std::cout << "Use Brains:" << std::endl;
	
	pets[0]->getBrain().setIdea("I am a Dog.", 0);
	pets[0]->getBrain().setIdea("I am hungry.", 1);
	pets[0]->getBrain().setIdea("I want to go for a walk.", 2);

	std::cout << "pets[1] is type " << pets[1]->getType()
				<< " and its idea 0 is: "
				<< pets[0]->getBrain().getIdea(0) << std::endl;
	std::cout << "pets[1] is type " << pets[1]->getType()
				<< " and its idea 1 is: " 
				<< pets[0]->getBrain().getIdea(1) << std::endl;
	std::cout << "pets[1] is type " << pets[1]->getType()
				<< " and its idea 2 is: " 
				<< pets[0]->getBrain().getIdea(2) << std::endl;
	
	std::cout << std::endl;

	std::cout << "Use Brains: Another example:" << std::endl;
	Brain brain1;
	
	brain1.setIdea("I have a brain.", 0);
	brain1.setIdea("Do I have a body?", 1);
	for(int i = 2; i < 7; i ++)
		brain1.setIdea("I am bored...", i);
	brain1.setIdea("Bye!!", 7);
	
	pets[5]->getBrain() = brain1;
	
	for(int i = 0; i < 8; i ++)
	{
		std::cout << "Idea num " << i << ": "
					<< pets[5]->getBrain().getIdea(i) << std::endl;
	}
	
	std::cout << std::endl;
	
	std::cout << "Check deep copy:" << std::endl;
	Dog dog1;
	Dog dog2;

	dog1.getBrain().setIdea("I am a dog.", 0);
	
	dog2 = dog1;
	
	std::cout << "dog2 idea 0 is (a copy of dog1): " 
				<< dog2.getBrain().getIdea(0) << std::endl;
	
	dog2.getBrain().setIdea("I am a wolf now!!", 0);
	
	std::cout << "Now, dog2 idea 0 is: " 
				<< dog2.getBrain().getIdea(0) << std::endl;

	std::cout << "dog1 idea 0 still: "
				<< dog1.getBrain().getIdea(0) << std::endl;

	Dog dog3(dog2);

	std::cout << "dog3 idea 0 is (a copt of dog2): "
				<< dog3.getBrain().getIdea(0) << std::endl;
	
	dog3.getBrain().setIdea("I wanna be a buterfly...", 1);
	
	std::cout << "dog3 idea 1 is: "
				<< dog3.getBrain().getIdea(1) << std::endl;
	
	std::cout << "dog2 idea 1 still: "
				<< dog2.getBrain().getIdea(1) << std::endl;
	
				
	std::cout << std::endl;
	
	std::cout << "Delete Animal objects: " << std::endl;
	for (int i = 0; i < 10; i++)
		delete(pets[i]);
	
	std::cout << std::endl;
		
	return (0);
}