class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int ans = 0;
        int n = p.size();
        vector<bool> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});

       
         int cnt = 0;

        while (cnt < n) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;

            ans += dis;

            cnt++;

            for (int i = 0; i < n; i++) {
                if(!vis[i]){
                int d = abs(p[node][0] - p[i][0]) + abs(p[node][1] - p[i][1]);
                pq.push({d, i});}
            }
        }

        return ans;
    }
};