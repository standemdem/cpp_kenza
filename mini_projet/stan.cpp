#include "stan.h"

Stan::Stan() {
	Ale = 0;
	rezrez = 0;
}
Stan::Stan(int Ale, int rezrez) {
	 this->Ale = Ale;
	 this->rezrez = rezrez;
}
	int Stan::getAle() const {
	return Ale;
}
	int Stan::getRezrez() const {
	return rezrez;
}
	void Stan::setAle(int Ale) {
	this->Ale = Ale;
}
	void Stan::setRezrez(int rezrez) {
	this->rezrez = rezrez;
}
