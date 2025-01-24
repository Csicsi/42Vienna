#include "../includes/DiamondTrap.hpp"

int main() {
	DiamondTrap diamondTrap;
	diamondTrap.whoAmI();
	diamondTrap.attack("target");

	DiamondTrap diamondTrap2("DiamondTrap2");
	diamondTrap2.whoAmI();
	diamondTrap2.attack("target");

	return 0;
}
