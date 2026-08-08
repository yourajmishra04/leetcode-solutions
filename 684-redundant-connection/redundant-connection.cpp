class Solution {
public:
    vector<int> ans;
    bool solve(vector<vector<int>>& mat, vector<bool>& vis, int node, int par) {

        if (node == par) {

            return 1;
        }
        vis[node] = 1;
        for (int curr : mat[node]) {
            if (!vis[curr] && solve(mat, vis, curr, par))
                return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> mat(n + 1);

        for (auto it : edges) {
            vector<bool> vis(n + 1, 0);

            if (solve(mat, vis, it[0], it[1]))
                return it;

            mat[it[0]].push_back(it[1]);

            mat[it[1]].push_back(it[0]);
        }
        return ans;
    }
};