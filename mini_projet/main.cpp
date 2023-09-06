#include "stan.h"
#include <iostream>

int main() {
	Stan obj;
	obj.setMain(42);
	std::cout << "Main = " << obj.getMain() << std::endl;

return 0;
}