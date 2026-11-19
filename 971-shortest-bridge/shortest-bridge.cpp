class Solution {
public:
    int n, m, k;
    vector<vector<int>> v;
    vector<vector<bool>> vis;
    void solve(vector<vector<int>>& grid, int i, int j) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0 ||
            vis[i][j] == 1)
            return;
        v[i][j] = k;
        vis[i][j] = 1;
        solve(grid, i + 1, j);
        solve(grid, i - 1, j);
        solve(grid, i, j + 1);
        solve(grid, i, j - 1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        k = 1;
        n = grid.size();
        m = grid[0].size();
        v.assign(n, vector<int>(m, 0));
        vis.assign(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && v[i][j] == 0) {
                    solve(grid, i, j);
                    k++;
                }
            }
        }
        vis.assign(n, vector<bool>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto [c, dis] = q.front();
            int x = c.first;
            int y = c.second;

            q.pop();
            if (v[x][y] == 2)
                return dis;
            // if (vis[x][y])
            //     continue;
            vis[x][y] = 1;
            if (x + 1 < n && !vis[x + 1][y]) {
                vis[x + 1][y] = 1;
                q.push({{x + 1, y}, dis + (v[x + 1][y] == 0)});
            }
            if (x - 1 >= 0 && !vis[x - 1][y]) {
                q.push({{x - 1, y}, dis + (v[x - 1][y] == 0)});
                vis[x - 1][y] = 1;
            }
            if (y + 1 < m && !vis[x][y + 1]) {
                q.push({{x, y + 1}, dis + (v[x][y + 1] == 0)});
                vis[x][y + 1] = 1;
            }
            if (y - 1 >= 0 && !vis[x][y - 1]) {
                q.push({{x, y - 1}, dis + (v[x][y - 1] == 0)});
                vis[x][y - 1] = 1;
            }
        }
        return 0;
    }
};