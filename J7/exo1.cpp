#include <iostream>
using namespace std;


template<typename T>
bool pairOuNon(T a){
    return (static_cast<int>(a)%2==0? true : false);
}

int main(){
    int a = 3;
    int b = 2;
    float c = 2.23;
    float d = 3.75;
    double e = 32.32;
    double f = 0;

    cout << (pairOuNon(a)? "pair":"impair")<<endl;
    cout << (pairOuNon(b)? "pair":"impair")<<endl;
    cout << (pairOuNon(c)? "pair":"impair")<<endl;
    cout << (pairOuNon(d)? "pair":"impair")<<endl;
    cout << (pairOuNon(e)? "pair":"impair")<<endl;
    cout << (pairOuNon(f)? "pair":"impair")<<endl;
    return 0;
}