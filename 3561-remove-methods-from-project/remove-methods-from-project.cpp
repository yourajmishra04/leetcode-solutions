class Solution {
public:
    set<int> rem;

    void solve(vector<vector<int>>& mat, int node) {

        if (rem.find(node) != rem.end())
            return;
        rem.insert(node);
        for (int it : mat[node])
            solve(mat, it);
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> mat(n), rev(n);
        for (auto it : invocations) {
            mat[it[0]].push_back(it[1]);
            rev[it[1]].push_back(it[0]);
        }
        rem.clear();
        solve(mat, k);
        vector<int> ans;
        bool flg = 0;
        for (auto node : rem) {
            flg = 0;
            for (auto parent : rev[node]) {
                if (rem.find(parent) == rem.end()) {

                    vector<int> ans;

                    for (int i = 0; i < n; i++)
                        ans.push_back(i);

                    return ans;
                }
            }
        }
          vector<int> fans;

        for(int i = 0; i < n; i++) {
            if(rem.find(i) == rem.end())
                fans.push_back(i);
        }

        return fans;
    }
};