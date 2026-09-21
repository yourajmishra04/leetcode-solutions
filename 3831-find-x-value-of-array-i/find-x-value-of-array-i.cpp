class Solution {
public:
    vector<long long> ans;
    int K, N;

    void solve(vector<int>& nums, int idx, vector<long long>& dp) {

        if (idx >= N)
            return;

        vector<long long> ndp(K, 0);

        
        int curr = nums[idx] % K;
        ndp[curr]++;

       
        for (int r = 0; r < K; r++) {
            if (dp[r] == 0)
                continue;

            int nr = ((long long)r * nums[idx]) % K;

            ndp[nr] += dp[r];
        }

        
        for (int r = 0; r < K; r++)
            ans[r] += ndp[r];

        solve(nums, idx + 1, ndp);
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        K = k;
        N = nums.size();

        ans.assign(K, 0);

        vector<long long> dp(K, 0);

        solve(nums, 0, dp);

        return ans;
    }
};