class Solution {
public:
    int n, m;
    int ans;
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i,
               int j, int& curr) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] == 0) {
            ans = max(ans, curr);
            return;
        }
        vis[i][j] = 1;
        curr++;
        solve(grid, vis, i + 1, j, curr);
        solve(grid, vis, i - 1, j, curr);
        solve(grid, vis, i, j + 1, curr);
        solve(grid, vis, i, j - 1, curr);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        ans = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    curr = 0;
                    solve(grid, vis, i, j, curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};