class Solution {
public:
    vector<set<int>> ans;

    void solve(vector<vector<int>>& mat, int node,int par, vector<bool>& vis) {

        vis[node] = 1;

        for (auto child : mat[node]) {
            if (!vis[child]) {
                ans[child].insert(par);
                solve(mat, child,par, vis);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        int n = numCourses;
        vector<vector<int>> mat(n);
        for (auto it : prerequisites) {
            mat[it[0]].push_back(it[1]);
        }
       ans.assign(n, {});

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, 0);
            solve(mat, i,i, vis);
        }

        n = queries.size();

        vector<bool> fans(n);
        for (int i = 0; i< n; i++) {
            int a = queries[i][0], b = queries[i][1];

            if (ans[b].find(a) != ans[b].end())
                fans[i] = 1;
            else
                fans[i] = 0;
        }

        return fans;
    }
};