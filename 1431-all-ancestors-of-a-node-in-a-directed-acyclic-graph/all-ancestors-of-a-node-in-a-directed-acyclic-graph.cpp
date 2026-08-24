class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<vector<int>>& mat, int node, int par ,  vector<bool>& vis) {
       vis[node]=1;
       
        for (auto child : mat[node]) {
          if(!vis[child]) { ans[child].push_back(par);
            solve(mat, child, par,vis);}
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mat(n);
        for (auto it : edges) {
            mat[it[0]].push_back(it[1]);
        }
        ans.resize(n);

        for (int i = 0; i < n; i++) {
               vector<bool> vis(n, false);
            solve(mat, i, i, vis);
        }
        return ans;
    }
};