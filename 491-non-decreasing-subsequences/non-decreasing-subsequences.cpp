class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& nums, vector<int>& curr, int idx) {

        if (idx == n ) {
            if (curr.size() > 1)
                ans.push_back(curr);
            return;
        }

        if (curr.size()== 0) {
            curr.push_back(nums[idx]);
            solve(nums, curr, idx + 1);
            curr.pop_back();
            solve(nums, curr, idx + 1);
        } else {

            if (curr.back() <= nums[idx]) {
                curr.push_back(nums[idx]);
                solve(nums, curr, idx + 1);
                curr.pop_back();
            }
            if (curr.back() != nums[idx]) {

                solve(nums, curr, idx + 1);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        ans.clear();
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};