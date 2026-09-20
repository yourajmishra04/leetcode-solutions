class Solution {
public:
    vector<vector<int>> dp;

    bool chk(string &s1, string &s2, string &s3, int i, int j) {
        int k = i + j;

        if (k == s3.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

      
        if (i < s1.size() && s1[i] == s3[k]) {
            ans = chk(s1, s2, s3, i + 1, j);
        }

       
        if (!ans && j < s2.size() && s2[j] == s3[k]) {
            ans = chk(s1, s2, s3, i, j + 1);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return chk(s1, s2, s3, 0, 0);
    }
};