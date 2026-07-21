class Solution {
public:
    int n, m;
    void solve(vector<vector<int>>& v, vector<vector<int>>& grid, int i, int j,
               int curr) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;
        if (curr >= v[i][j])
            return;
        v[i][j] = min(curr, v[i][j]);

        curr++;

        solve(v, grid, i + 1, j, curr);
        solve(v, grid, i - 1, j, curr);
        solve(v, grid, i, j + 1, curr);
        solve(v, grid, i, j - 1, curr);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    solve(v, grid, i, j, 0);
                }
            }
        }

        int ans = -1;
     int z=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==0) {
                    z++;
                    continue;
                }
                ans = max(ans, v[i][j]);
            }
        }

        if(z==m*n) return 0;
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};