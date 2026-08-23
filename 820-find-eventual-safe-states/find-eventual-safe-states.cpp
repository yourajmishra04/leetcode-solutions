class Solution {
public:
 vector<int>dp;
 vector<bool>vis;
   bool solve (vector<vector<int>>& graph , int node){
    if(graph[node].empty()) return dp[node]=true;
    if(dp[node]!=-1) return dp[node];
         bool ans = 1;
     if(vis[node]==1) return 0;
      vis[node]=1;
         for(auto it : graph[node]) ans=ans && solve(graph , it);

         return dp[node]=ans;

   }

  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        dp.assign(n,-1);
        vis.assign(n,0);
        for(int i=0;i<n;i++) if(!vis[i]) solve(graph , i);

        vector<int>ans;
        for(int i=0;i<n;i++) if(dp[i]==1)  ans.push_back(i);
        return ans;
    }
};