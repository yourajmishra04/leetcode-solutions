class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!dq.empty()) {

            auto [i, j] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {

                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni < 0 || ni >= n ||
                    nj < 0 || nj >= m)
                    continue;

                int cost = grid[ni][nj];

                if (dist[i][j] + cost < dist[ni][nj]) {

                    dist[ni][nj] = dist[i][j] + cost;

                    if (cost == 0)
                        dq.push_front({ni, nj});
                    else
                        dq.push_back({ni, nj});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};