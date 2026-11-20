class Solution {
public:
    vector<vector<int>> v;
    int N;
    int ans = 0;
    vector<bool> vis;
    int solve(vector<bool>& hasApple, int node) {

        int temp = 0;
        
        vis[node] = 1;
        
        for (int x : v[node]) {
            if (!vis[x])
                temp += solve(hasApple, x);
        }
          if(temp>0 || hasApple[node])  if(node>0)temp+=2;
        return temp;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        N = n;
        v.resize(n);
        vis.assign(n, 0);
        for (auto it : edges) {
            int x = it[0], y = it[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = solve(hasApple, 0);
        return ans;
    }
};