class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int h = 0;

    void solve(queue<int>& q, vector<vector<int>>& mat) {
        if (q.empty())
            return;
        h++;
        vector<int> temp;
        queue<int> qq;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for (int child : mat[node])
                qq.push(child);
        }

        ans.push_back(temp);
        solve(qq, mat);
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        n = parent.size();
        vector<vector<int>> mat(n);
        for (int i = 1; i < n; i++) {
            mat[parent[i]].push_back(i);
        }

        queue<int> q;
        ans.clear();
        q.push(0);
        h=0;
        solve(q, mat);
        n = ans.size();
        long long fans = 0;

        for (int i = 0; i < n; i++) {
            for (int node : ans[i]) {
                fans += 1LL * nums[node] * (h - (i+1 )+ 1);
            }
        }
        return fans;
    }
};