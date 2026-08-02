class Solution {
public:
    int ans;

    void solve(vector<int>& nums, int target, int curr, int idx) {
        if (idx == nums.size()) {
            if (curr == target)
                ans++;
            return;
        }

        solve(nums, target, curr + nums[idx], idx + 1);
        solve(nums, target, curr - nums[idx], idx + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        solve(nums, target, 0, 0);
        return ans;
    }
};