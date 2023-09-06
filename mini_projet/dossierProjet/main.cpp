#include "stan.h"
#include <iostream>

int main() {
	Stan obj;
	obj.setA(42);
	obj.setB(42);
	obj.setC(42);
	obj.setD(42);
	obj.setE(42);
	cout << "A = " << obj.getA() << endl;
	cout << "B = " << obj.getB() << endl;
	cout << "C = " << obj.getC() << endl;
	cout << "D = " << obj.getD() << endl;
	cout << "E = " << obj.getE() << endl;

return 0;
}