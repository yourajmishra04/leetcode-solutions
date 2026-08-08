class Solution {
public:
    vector<pair<int, int>> v;
    int tot = 0;

    void get(vector<vector<int>>& mat, vector<long long>& ans, long long node, long long up) {

        long long l = max(v[node].first, 1), r = max(v[node].second, 1);

        ans[node] = up * l * r;

        if (mat[node].size() > 0)
            get(mat, ans, mat[node][0], tot - v[node].first);

        if (mat[node].size() > 1)
            get(mat, ans, mat[node][1], tot - v[node].second);
    }

    pair<int, int> solve(vector<vector<int>>& mat, int node) {

        if (mat[node].size() == 0)
            return v[node] = {0, 0};
        int l = 0, r = 0;

        pair<int, int> lft = solve(mat, mat[node][0]);
        l = 1 + lft.first + lft.second;

        if (mat[node].size() > 1) {
            pair<int, int> rght = solve(mat, mat[node][1]);
            r = 1 + rght.first + rght.second;
        }

        return v[node] = {l, r};
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> mat(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1)
               mat[ parents[i]].push_back(i);
        }
        v.clear();
        v.assign(n,pair<int,int>{0,0});
        vector<long long> ans(n);
      
        solve(mat , 0);
          tot = v[0].first + v[0].second + 1;
        get(mat , ans, 0, 1);
        sort(ans.rbegin(),ans.rend());

        long long i=1, fans=1;
        while(i<n && ans[i]==ans[0]) {
            fans++;
            i++;
        }
        return fans;

    }
};