#ifndef STAN_H
#define STAN_H

class Stan {
public:
	Stan();
	Stan(int a, int b);

	int getA() const;
	void setA(int a);
	int getB() const;
	void setB(int b);
	

private:
	int a;
	int b;
};

#endif