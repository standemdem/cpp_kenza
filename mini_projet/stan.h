#ifndef STAN_H
#define STAN_H

class Stan {
public:
	Stan();
	Stan(int main);

	int getMain() const;

	void setMain(int main); 


private:
	int main;
};

#endif