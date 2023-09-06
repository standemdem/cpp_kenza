#include "tutu.h"
#include <iostream>

int main() {
	system("chcp 65001");
	Tutu obj;
	obj.setA(42);
	obj.setB(42);
	obj.setA(42);
	cout << "A = " << obj.getA() << endl;
	cout << "B = " << obj.getB() << endl;
	cout << "A = " << obj.getA() << endl;

return 0;
}