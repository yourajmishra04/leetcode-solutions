class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> mat(n);
        for (auto it : edges) {
            mat[it[0]].push_back({it[1], it[2], it[3]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> val(n, INT_MAX);
        val[0] = 0;

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time != val[node])
                continue;

            if (node == n - 1)
                return time;

            for (auto [a, b, c] : mat[node]) {
                if (time > c)
                    continue;

                int newtime = max(time, b) + 1;
                if (newtime < val[a]){
                    val[a]=newtime;
                    pq.push({newtime, a});}
            }
        }
        return -1;
    }
};