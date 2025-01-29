
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		dog->makeSound(); //will output the cat sound!
		cat->makeSound();
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongCat2 = new WrongCat();

	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat2->getType() << " " << std::endl;

	wrongAnimal->makeSound();
	std::cout << "This should be an animal sound: ";
	wrongCat->makeSound();
	std::cout << "This should be a cat sound: ";
	wrongCat2->makeSound();

	delete wrongAnimal;
	delete wrongCat;
	delete wrongCat2;

	return 0;
}
