#include "stan.h"

Stan::Stan() {
	main = 0;
}
Stan::Stan(int main) {
	 this->main = main;
}
int Stan::getMain() const {
	return main;
}
void Stan::setMain(int main) {
	this->main = main;
}
