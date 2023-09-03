#include "stan.h"
#include <iostream>

int main() {
	Stan obj;
	obj.setA(42);
	obj.setB(42);
	std::cout << "A = " << obj.getA() << std::endl;
	std::cout << "B = " << obj.getB() << std::endl;

return 0;
}