#ifndef STAN_H
#define STAN_H
#include <iostream>
using namespace std;


class Stan {
public:
	Stan();
	Stan(int a, int b, int c, int d, int e);

	int getA() const;
	int getB() const;
	int getC() const;
	int getD() const;
	int getE() const;

	void setA(int a); 
	void setB(int b); 
	void setC(int c); 
	void setD(int d); 
	void setE(int e); 


private:
	int a;
	int b;
	int c;
	int d;
	int e;
};

#endif