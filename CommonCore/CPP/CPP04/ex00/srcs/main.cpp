
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wrong = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << wrong->getType() << " " << std::endl;
std::cout << wrongCat->getType() << " " << std::endl;
wrong->makeSound();
wrongCat->makeSound();

delete meta;
delete j;
delete i;
delete wrong;
delete wrongCat;

return 0;
}
