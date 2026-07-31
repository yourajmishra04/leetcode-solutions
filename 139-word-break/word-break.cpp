class Solution {
public:
    vector<int> dp;
    string str;
    vector<string> word;

    bool solve(int k) {
       int n = str.size();
       if(k>n) return 0;
        if (k == n )
            return 1;
            if(dp[k]!=-1) return dp[k]; 
        bool ans = 0;
        for (auto s : word) {
            if (s.size() <= n - k + 1) {
                string comp = str.substr(k, s.size());
                if(comp == s) ans= ans || solve(k+s.size());
            }
        }
        return dp[k]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        dp.assign(n,-1);
        str = s;
        word = wordDict;
        return solve(0);
    }
};