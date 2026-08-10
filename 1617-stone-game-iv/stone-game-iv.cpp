class Solution {
public:
    vector<vector<int>> dp;
    bool chk(int n) {
        int k = sqrt(n);
        if (k * k == n)
            return 1;
        return 0;
    }

    bool solve(int n, bool flg) {
        bool ans;
        if (n == 0) {
            if (flg == 0)
                return dp[n][flg] = 1;
            else
                return dp[n][flg] = 0;
        }
        if (dp[n][flg] != -1)
            return dp[n][flg];
        if (flg == 1) {
            ans = 0;

            for (int i = 1; i*i <= n; i++)
               
                    ans = ans || solve(n - i*i, 0);
        } else {
            ans = 1;
            for (int i = 1; i*i <= n; i++)
              
                    ans = ans && solve(n - i*i, 1);
        }
        return dp[n][flg] = ans;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, vector<int>(2, -1));
        bool flg = 1;
        return solve(n, flg);
    }
};