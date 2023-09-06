#ifndef STAN_H
#define STAN_H

class Stan {
public:
	Stan();
	Stan(int a, int b);

	int getA() const;
	int getB() const;

	void setA(int a); 
	void setB(int b); 


private:
	int a;
	int b;
};

#endif