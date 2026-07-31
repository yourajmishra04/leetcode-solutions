class Solution {
public:
    int ans = 0;
    int cnt;
    int n;
    int m;
    void solve(vector<vector<int>>& grid, int i, int j, int curr) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2) {
            if (curr == cnt+1)
                ans++;
            return;
        }

        grid[i][j] = -1;
        curr++;
        solve(grid, i + 1, j, curr);
        solve(grid, i - 1, j, curr);
        solve(grid, i, j + 1, curr);
        solve(grid, i, j - 1, curr);
        curr--;
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt = 0;
        int ii, jj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ii = i;
                    jj = j;
                }
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }
        solve(grid, ii, jj, 0);
        return ans;
    }
};