
/* if graph has vertices with  two odd degrees and remaning even degrees is called eulerpath
    if there is no odd degrees then it is said to be as the euler circuit
*/

class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
        int odd=0;
        for(int i=0;i<V;i++)
        {
            if(adj[i].size()%2==1)
            {
                odd++;
            }
        }
        if(odd==2)
        {
            return 1;
        }else if(odd==0)
        {
            return 2;
        }else{
            return 0;
        }
	}
};