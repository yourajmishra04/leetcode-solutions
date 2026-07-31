class Solution {
public:
    vector<string> ans;
    string str;
    vector<string> word;
    vector<int> dp;
    bool solve(int k, string curr) {
        int n = str.size();
        if (k > n)
            return 0;
        if (k == n) {
            ans.push_back(curr);
            return 1;
        }
        if (dp[k] == 0)
            return 0;
        for (auto s : word) {
            if (s.size() <= n - k + 1) {
                string comp = str.substr(k, s.size());
                if (comp == s)
                    solve(k + s.size(), curr + " " + comp);
            }
        }
        return dp[k] = 1;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear();
        int n = s.size();
        dp.assign(n, -1);
        str = s;
        word = wordDict;
        string curr = "";
        solve(0, curr);
        for(auto& it : ans){
            if(it.size()>0) it.erase(0,1);
        }
        return ans;
    }
};