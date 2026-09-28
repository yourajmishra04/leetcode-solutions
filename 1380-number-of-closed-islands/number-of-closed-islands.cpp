class Solution {
public:
    int n, m;
    vector<vector<bool>> mat;
    bool flg;
    void solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1 || mat[i][j])
            return;

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            flg = 0;

        mat[i][j] = 1;

        solve(grid, i + 1, j);
        solve(grid, i - 1, j);
        solve(grid, i, j + 1);
        solve(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        mat.assign(n, vector<bool>(m, 0));
       
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flg = 1;
                if (!mat[i][j] && grid[i][j] == 0) {
                    solve(grid, i, j);
                    if (flg == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};