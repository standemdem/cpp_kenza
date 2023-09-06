#include "stan.h"

Stan::Stan() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
}
Stan::Stan(int a, int b, int c, int d, int e) {
	 this->a = a;
	 this->b = b;
	 this->c = c;
	 this->d = d;
	 this->e = e;
}
int Stan::getA() const {
	return a;
}
int Stan::getB() const {
	return b;
}
int Stan::getC() const {
	return c;
}
int Stan::getD() const {
	return d;
}
int Stan::getE() const {
	return e;
}
void Stan::setA(int a) {
	this->a = a;
}
void Stan::setB(int b) {
	this->b = b;
}
void Stan::setC(int c) {
	this->c = c;
}
void Stan::setD(int d) {
	this->d = d;
}
void Stan::setE(int e) {
	this->e = e;
}
