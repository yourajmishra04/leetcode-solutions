class Solution {
public:
    double f(int idx, vector<int>& nums, int k,
             vector<vector<double>>& dp) {

        int n = nums.size();

        if(idx == n)
            return 0;

        if(k == 0)
            return -1e18;

        if(dp[idx][k] != -1)
            return dp[idx][k];

        double sum = 0;
        double ans = -1e18;

        for(int i = idx; i < n; i++) {

            sum += nums[i];

            double len = i - idx + 1;
            double avg = sum / len;

            ans = max(ans,
                      avg + f(i + 1, nums, k - 1, dp));
        }

        return dp[idx][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<double>> dp(
            n,
            vector<double>(k + 1, -1)
        );

        return f(0, nums, k, dp);
    }
};