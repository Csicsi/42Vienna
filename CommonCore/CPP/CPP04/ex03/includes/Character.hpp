#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	AMateria *_inventory[4];
	void _deleteInventory();
	void _copyInventory(const Character &other);
public:
	Character();
	Character(std::string name);
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
