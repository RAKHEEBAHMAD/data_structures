#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    
    return gcd(b,a%b);
}

int main()
{
    cout<<gcd(4,6);
    return 0;
}

// lcm

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
