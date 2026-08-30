class Solution {
public:
   
    

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       vector<int>ans(n+1,0);
  
        vector<vector<int>> mat(n+1);
         for (auto &it : paths) {
            mat[it[0]].push_back(it[1]);
            mat[it[1]].push_back(it[0]);
        }

       for(int i=1;i<=n;i++){
                
                vector<bool>used(5,0);
                for(int adj : mat[i]){
                    if(ans[adj]!=0) used[ans[adj]]=1;

                }
                for(int c=1;c<5;c++){
                    if(!used[c]){
                        ans[i]=c;
                        break;
                    }
                }
       }
       ans.erase(ans.begin());
       return ans;
    }
};