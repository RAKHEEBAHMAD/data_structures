#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    int tsum=(n*(n+1))/2;
    vector<int>v1;
    vector<int>v2;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        if(tsum%i)
        {
            s1+=i;
            v1.push_back(i);
        }else{
            s2+=i;
            v2.push_back(i);
        }
    }
    if(s1==tsum/2 and s2==tsum/2)
    {
        cout<<"YES"<<endl;
        cout<<v1.size()<<endl;
        for(auto i:v1)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<v2.size()<<endl;
        for(auto i:v2)
        {
            cout<<i<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    
}