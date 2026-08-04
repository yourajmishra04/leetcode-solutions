class Solution {
public:
     vector<bool> flg; 

     int solve(vector<vector<int>>& mat , int node,int par){

             int n=mat.size();

             int ans=0;
            
             
             int l;
             
             for(auto it : mat[node]){
                if(it==par) continue;
              l=solve(mat,it,node);
              if(l>0 || flg[it])
              ans+= l+2 ;

             }
              return ans;



     }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>mat(n);
        flg=hasApple;

        for(auto it : edges){
            mat[it[0]].push_back(it[1]);
            
            mat[it[1]].push_back(it[0]);
        }

        return solve(mat,0,-1);
    }
};