#include "stan.h"

Stan::Stan() {
	bonjour = 0;
	aurevoir = 0;
}
Stan::Stan(int bonjour, int aurevoir) {
	 this->bonjour = bonjour;
	 this->aurevoir = aurevoir;
}
int Stan::getBonjour() const {
	return bonjour;
}
int Stan::getAurevoir() const {
	return aurevoir;
}
void Stan::setBonjour(int bonjour) {
	this->bonjour = bonjour;
}
void Stan::setAurevoir(int aurevoir) {
	this->aurevoir = aurevoir;
}
