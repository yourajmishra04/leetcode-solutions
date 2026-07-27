class Solution {
public:

  bool ans;
  void solve(vector<vector<int>> &mat , vector<bool>& vis, int s , int d){
    if(vis[s]) return ;
    if(s==d){
        ans=1;
        return;
    }
    vis[s]=1;
     for(auto x : mat[s]) solve(mat , vis , x , d);
  }
    

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>mat(n);
        for(auto it : edges){
            mat[it[0]].push_back(it[1]);
             mat[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        ans=0;
        solve(mat,vis , source,destination);
        return ans;
    }
};