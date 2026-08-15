class Solution {
public:
    vector<int> ans;
    int solve(vector<vector<int>>& mat, vector<int>& quiet, int node,
              vector<bool>& vis) {

        if (mat[node].empty())
            return ans[node] = node;
        if (vis[node])
            return ans[node];
        vis[node] = 1;

        int tans = node;

        for (int x : mat[node]) {
            int temp = solve(mat, quiet, x , vis);

            if (quiet[tans] > quiet[temp])
                tans = temp;
        }

        return ans[node] = tans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        ans.assign(n, -1);
        vector<bool> vis(n, 0);
        vector<vector<int>> mat(n);
        for (auto& it : richer) {
            mat[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                solve(mat, quiet, i, vis);
        }
        return ans;
    }
};