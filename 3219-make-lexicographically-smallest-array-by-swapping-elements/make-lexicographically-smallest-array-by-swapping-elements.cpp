class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        vector<int> ans(n);
        sort(v.begin(), v.end());
        int i = 0, j;
        while (i < n) {
            vector<int> ele;
            vector<int> pos;
            j = i + 1;
            ele.push_back(v[i][0]);
            pos.push_back(v[i][1]);
            while (j < n && v[j][0] <= v[j - 1][0] + k) {
                ele.push_back(v[j][0]);
                pos.push_back(v[j][1]);
                j++;
            }
            sort(pos.begin(), pos.end());
            for (int i = 0; i < pos.size(); i++)
                ans[pos[i]] = ele[i];
            i = j;
        }
        return ans;
    }
};