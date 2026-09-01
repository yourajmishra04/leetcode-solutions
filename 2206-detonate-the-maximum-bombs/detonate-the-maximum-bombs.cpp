class Solution {
public:
    void solve(vector<vector<int>>& mat, int node, int& temp,
               vector<bool>& vis) {

        if (vis[node])
            return;

        vis[node] = 1;
        temp++;

        for (int i : mat[node])
            solve(mat, i, temp, vis);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> mat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long d =1LL *
                    abs(bombs[i][0] - bombs[j][0]) * abs(bombs[i][0] - bombs[j][0]);
                d +=
                    (1LL* abs(bombs[i][1] - bombs[j][1]) * abs(bombs[i][1] - bombs[j][1]));
                long long lim= bombs[i][2];
                 lim*=lim;
                if (d <= lim) {
                    mat[i].push_back(j);
                    
                }
            }
        }

       
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, 0);
                int temp = 0;
                solve(mat, i, temp, vis);
                ans = max(temp, ans);
            
        }
        return ans;
    }
};