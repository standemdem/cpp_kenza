#include "stan.h"
#include <iostream>

int main() {
	Stan obj;
	obj.setAle(42);
	obj.setRezrez(42);
	std::cout << "Ale = " << obj.getAle() << std::endl;
	std::cout << "Rezrez = " << obj.getRezrez() << std::endl;

return 0;
}