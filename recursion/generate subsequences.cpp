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


/*Printing Subsequnces Equal to K*/
void generatesubarrays(vector<int> v,int start,int end,vector<int>& res,int sum,int tempsum)
{
    if(start==end)
    {
        if(tempsum==sum)
        {
            for(auto i:res)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        }
        
        
        return;
    }
    
    res.push_back(v[start]);
    tempsum+=v[start];
    generatesubarrays(v,start+1,end,res,sum,tempsum);
    
    
    res.pop_back();
    tempsum-=v[start];
    generatesubarrays(v,start+1,end,res,sum,tempsum);
    
}

int main()
{
    vector<int>v={2,1,1};
    int sum=2;
    vector<int>res;
    
    generatesubarrays(v,0,v.size(),res,sum,0);
    
} 


/*Print First Subseuqce equal to K*/
#include<bits/stdc++.h>
using namespace std;

bool generatesubarrays(vector<int> v,int start,int end,vector<int>& res,int sum,int tempsum)
{
    if(start==end)
    {
        if(tempsum==sum)
        {
            for(auto i:res)
            {
                cout<<i<<" ";
            }
            return true;
        }
        else{
            return false;
        }
        
    }
    
    res.push_back(v[start]);
    tempsum+=v[start];
    if(generatesubarrays(v,start+1,end,res,sum,tempsum))
    {
        return true;
    }
    
    
    res.pop_back();
    tempsum-=v[start];
    if(generatesubarrays(v,start+1,end,res,sum,tempsum))
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int>v={1,1,2};
    int sum=2;
    vector<int>res;
    
    generatesubarrays(v,0,v.size(),res,sum,0);
    
} 


/*Count the subsequces equal to K*/

#include<bits/stdc++.h>
using namespace std;

int generatesubarrays(vector<int> v,int start,int end,vector<int>& res,int sum,int tempsum)
{
    if(start==end)
    {
        if(tempsum==sum)
        {
            return 1;
        }
        else{
            return 0;
        }
        
    }
    
    res.push_back(v[start]);
    tempsum+=v[start];
    int l = generatesubarrays(v,start+1,end,res,sum,tempsum);
    
    
    res.pop_back();
    tempsum-=v[start];
    int r= generatesubarrays(v,start+1,end,res,sum,tempsum);
    
    return l+r;
}

int main()
{
    vector<int>v={1,1,2};
    int sum=2;
    vector<int>res;
    
    int c=generatesubarrays(v,0,v.size(),res,sum,0);
    cout<<c;
} 