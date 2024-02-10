#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << endl;
        }
    }

    return 0;
}


/*  Recusrion */

#include<bits/stdc++.h>
using namespace std;

void generatesubarrays(vector<int> v,int start,int end,vector<int>& res)
{
    if(start==end)
    {
        for(auto i:res)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    
    res.push_back(v[start]);
    generatesubarrays(v,start+1,end,res);
    
    
    res.pop_back();
    generatesubarrays(v,start+1,end,res);
    
}

int main()
{
    vector<int>v={1,2,3};
    
    vector<int>res;
    
    generatesubarrays(v,0,v.size(),res);
    
}