class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;

    void f(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        f(grid, i + 1, j);
        f(grid, i - 1, j);
        f(grid, i, j + 1);
        f(grid, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                    grid[i][j] == 1)
                    f(grid, i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};