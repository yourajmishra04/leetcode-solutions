class Solution {
public:
    vector<long long> fre;
    vector<long long> mn;
    int mod = 1e9 + 7;
    void
    solve(vector<vector<pair<int, int>>>& mat,
          priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                         greater<pair<long long, int>>>& pq) {

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (it.first > mn[it.second])
                continue;
            for (auto nxt : mat[it.second]) {
                long long cost = it.first + nxt.second;
                if (cost > mn[nxt.first])
                    continue;
                else if (cost < mn[nxt.first]) {
                    pq.push({cost, nxt.first});
                    fre[nxt.first] = fre[it.second];
                    mn[nxt.first] = cost;

                } else {
                    fre[nxt.first] = (fre[nxt.first] + fre[it.second]) % mod;
                }
            }
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        fre.assign(n, 0);
        mn.assign(n, LLONG_MAX);
        mn[0] = 0;
        fre[0] = 1;
        vector<vector<pair<int, int>>> mat(n);
        for (auto it : roads) {
            mat[it[0]].push_back({it[1], it[2]});
            mat[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        solve(mat, pq);
        return fre[n - 1];
    }
};