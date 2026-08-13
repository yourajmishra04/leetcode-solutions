class Solution {
public:
    int ans = 0;
    vector<vector<int>>dp;
    int solve(int k, vector<int>& prices, int idx, int tran) {

        if (idx >= prices.size() || tran == k*2)
            return 0;
        if(dp[idx][tran]!=-1) return dp[idx][tran];
        if (tran % 2 == 0) {
            return dp[idx][tran]=max(-prices[idx] + solve(k, prices, idx + 1, tran + 1),
                       solve(k, prices, idx + 1, tran));
        }

        return dp[idx][tran]=max(prices[idx] + solve(k, prices, idx + 1, tran + 1),
                   solve(k, prices, idx + 1, tran));
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size()+1,vector<int>(2*k+1 , -1));
        return solve(k,prices,0,0);
    }
};