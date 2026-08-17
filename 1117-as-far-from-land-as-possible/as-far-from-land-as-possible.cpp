class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<vector<int>>& grid, int i, int j, int curr) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 1 ||
            ans[i][j] <= curr)
            return;
        ans[i][j] = curr;
        solve(grid, i + 1, j, curr + 1);
        solve(grid, i - 1, j, curr + 1);
        solve(grid, i, j + 1, curr + 1);
        solve(grid, i, j - 1, curr + 1);
    }
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        ans.assign(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    solve(grid, i + 1, j, 1);
                    solve(grid, i - 1, j, 1);
                    solve(grid, i, j + 1, 1);
                    solve(grid, i, j - 1, 1);
                }
            }
        }
        int fans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    fans = max(fans, ans[i][j]);
            }
        }
        if(fans==INT_MAX || fans==-1) return -1;
        return fans;
    }
};