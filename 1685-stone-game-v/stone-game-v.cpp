class Solution {
public:
    vector<int> stone;
    vector<vector<int>> dp;
    int solve(int l, int r) {
        if (l == r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0, sum = 0;
        for (int i = l; i <= r; i++)
            sum += stone[i];
        sum /= 2;
        int temp = 0;

        for (int i = l; i <= r; i++) {
            temp += stone[i];
            if (temp > sum)
                break;
            ans = max(ans, temp + solve(l, i));
        }
        temp = 0;
        for (int i = r; i >= l; i--) {
            temp += stone[i];
            if (temp > sum)
                break;
            ans = max(ans, temp + solve(i, r));
        }
        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& Stone) {
        stone = Stone;
        int n = stone.size();

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(0, n - 1);
    }
};