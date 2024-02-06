#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int mx;
    cin>>mx;
    long long int moves=0;
    for(int i=1;i<n;i++)
    {
        long long int ele;
        cin>>ele;
        mx=max(mx,ele);
        moves+=(mx-ele);
    }
    cout<<moves;
}