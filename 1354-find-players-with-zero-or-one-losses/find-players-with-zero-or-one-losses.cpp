class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        for (auto it : matches) {
            mp[it[0]] = 0;
            mp[it[1]] = 0;
        }
        for (auto it : matches)
            mp[it[1]]++;

        vector<vector<int>> ans(2);
        for (auto it : mp) {

            if (it.second == 0) {
                ans[0].push_back(it.first);
            }
            if (it.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[0].begin(), ans[0].end());
        return ans;
    }
};