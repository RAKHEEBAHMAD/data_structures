#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int tsum = (n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        int ele;
        cin>>ele;
        sum+=ele;
    }
    cout<<tsum-sum;
}