class Solution {
public:
    int n, m;
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            q;
        q.push({0, 0, 0});
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        while (!q.empty()) {

            auto [a, b, c] = q.top();
            q.pop();
            if (a == n - 1 && b == m - 1) {
                return c;
            }
            if (a + 1 < n && vis[a + 1][b] > max(c, abs(heights[a][b] -
                                                        heights[a + 1][b]))) {
                vis[a + 1][b] = max(c, abs(heights[a][b] - heights[a + 1][b]));
                q.push(
                    {a + 1, b, max(c, abs(heights[a][b] - heights[a + 1][b]))});
            }
            if (b + 1 < m && vis[a][b + 1] > max(c, abs(heights[a][b] -
                                                        heights[a][b + 1]))) {
                vis[a][b + 1] = max(c, abs(heights[a][b] - heights[a][b + 1]));
                q.push(
                    {a, b + 1, max(c, abs(heights[a][b] - heights[a][b + 1]))});
            }
            if (a - 1 >= 0 && vis[a - 1][b] > max(c, abs(heights[a][b] -
                                                         heights[a - 1][b]))) {
                vis[a - 1][b] = max(c, abs(heights[a][b] - heights[a - 1][b]));
                q.push(
                    {a - 1, b, max(c, abs(heights[a][b] - heights[a - 1][b]))});
            }
            if (b - 1 >= 0 && vis[a][b - 1] > max(c, abs(heights[a][b] -
                                                         heights[a][b - 1]))) {
                vis[a][b - 1] = max(c, abs(heights[a][b] - heights[a][b - 1]));
                q.push(
                    {a, b - 1, max(c, abs(heights[a][b] - heights[a][b - 1]))});
            }
        }
        return ans;
    }
};