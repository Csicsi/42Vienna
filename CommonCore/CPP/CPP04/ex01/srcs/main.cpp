
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main() {
	std::cout << "***Subject tests***" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n***Array of animals***" << std::endl;
	{
		const int n = 10;
		Animal* animals[n];

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < n; i++)
			delete animals[i];
	}

	std::cout << "\n***Testing copy is deep***" << std::endl;
	{
		Cat cat1;
		cat1.setIdea("I am a cat", 0);
		Cat cat2(cat1);
		cat2.setIdea("I am a cat too", 0);

		std::cout << "Cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "Cat2 idea: " << cat2.getIdea(0) << std::endl;
	}

	std::cout << "\n***Testing assignation is deep***" << std::endl;
	{
		Cat cat1;
		cat1.setIdea("I am a cat", 0);
		Cat cat2;
		cat2.setIdea("I am a cat too", 0);
		cat2 = cat1;

		std::cout << "Cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "Cat2 idea: " << cat2.getIdea(0) << std::endl;
	}

	std::cout << "\n***Testing too many ideas***" << std::endl;
	{
		Cat cat;
		for (int i = 0; i < 101; i++) {
			cat.setIdea("I am a cat", i);
		}
		std::cout << "Cat idea: " << cat.getIdea(99) << std::endl;
		std::cout << "Cat idea: " << cat.getIdea(100) << std::endl;
	}

	return 0;
}
