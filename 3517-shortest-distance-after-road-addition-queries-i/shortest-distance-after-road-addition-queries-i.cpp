class Solution {
public:
    vector<int> ans;
    int N;
    int dis;
    void solve(vector<vector<int>>& mat) {
        vector<int> dist(N, -1);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            if (node == N - 1) {
                dis = d;
                break;
            }
            for (auto it : mat[node])
                if (dist[it] == -1) {
                    dist[it] = d + 1;
                    q.push({it, d + 1});
                }
        }

        return;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> mat(n);
        ans.clear();
        N = n;
        for (int i = 0; i < n - 1; i++)
            mat[i].push_back(i + 1);
        for (auto q : queries) {
            dis = INT_MAX;
            mat[q[0]].push_back(q[1]);
            solve(mat);
            ans.push_back(dis);
        }
        return ans;
    }
};