class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> vis;
    int m, n;
    void solve(vector<vector<int>>& grid, int row, int col, int color,
               int prev) {
        if (row < 0 || col < 0 || row >= n || col >= m ||
            grid[row][col] != prev || vis[row][col])
            return;
        vis[row][col] = 1;
        ans[row][col] = color;

        solve(grid, row + 1, col, color, prev);
        solve(grid, row - 1, col, color, prev);
        solve(grid, row, col + 1, color, prev);
        solve(grid, row, col - 1, color, prev);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {

        n = grid.size();
        m = grid[0].size();
        ans.assign(n, vector<int>(m, -1));
        vis.assign(n, vector<bool>(m, 0));
        solve(grid, row, col, color, grid[row][col]);
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (ans[i][j] == color && ans[i - 1][j] != -1 &&
                    ans[i + 1][j] != -1 && ans[i][j - 1] != -1 &&
                    ans[i][j + 1] !=-1)
                    ans[i][j] = grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == -1)
                    ans[i][j] = grid[i][j];
            }
        }

        return ans;
    }
};