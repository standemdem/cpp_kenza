#include <iostream>

using namespace std;

// int sommeChiffres(int n)
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     return n + sommeChiffres(n-1);
// }

int sommeChiffres2(int n)
{
    int reste = n%10;
    int remain = n/10;
    if (remain < 10)
    {
        return remain;
    }
    return reste + sommeChiffres2(remain);
}

int main()
{
    // cout << sommeChiffres(4) << endl;
    cout << sommeChiffres2(10) << endl;
    return 0;
}