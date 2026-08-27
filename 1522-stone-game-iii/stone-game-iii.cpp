class Solution {
public:
vector<int>dp;
    int solve(vector<int>& s, int idx) {
       int n=s.size();
        if (idx >= n)
            return 0;

            if(dp[idx]!=INT_MIN) return dp[idx];
        int diff = INT_MIN;

        diff = max(diff, s[idx] - solve(s, idx + 1));
        if (idx + 1 < n)
            diff = max(diff, s[idx] + s[idx + 1] - solve(s, idx + 2));
        if (idx + 2 < n)
            diff =
                max(diff, s[idx] + s[idx + 1] + s[idx + 2] - solve(s, idx + 3));
        return dp[idx]=diff;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.resize(n,INT_MIN);
        int result = solve(stoneValue, 0);
        if (result > 0)
            return "Alice";
        else if (result < 0)
            return "Bob";
        else
            return "Tie";
    }
};