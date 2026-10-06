class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = n - 1;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                ans[i] = nums[k];
                k--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[i] = nums[k];
                k--;
            }
        }
        nums = ans;
    }
};