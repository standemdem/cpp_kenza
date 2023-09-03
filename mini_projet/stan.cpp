#include "stan.h"

Stan::Stan() {
	a = 0;
	b = 0;
}
Stan::Stan(int a, int b) {
	 this->a = a;
	 this->b = b;
}
int Stan::getA() const {
	return a;
}
int Stan::getB() const {
	return b;
}
void Stan::setA(int a) {
	this->a = a;
}
void Stan::setB(int b) {
	this->b = b;
}
