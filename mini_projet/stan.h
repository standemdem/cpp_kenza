#ifndef STAN_H
#define STAN_H

class Stan {
public:
	Stan();
	Stan(int Ale, int rezrez);

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


private:
	int Ale;
	int rezrez;
};

#endif