class Solution {
public:
    stack<char> st;

    int n;
    vector<vector<int>> dp;
    bool solve(string s, int idx, int cnt) {
        if (cnt < 0)
            return 0;
        if (idx == n) {
            if (cnt == 0)
                return 1;
            else
                return 0;
        }
        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        if (s[idx] == '(') {
            cnt++;
            return solve(s, idx + 1, cnt);
        }

        else if (s[idx] == ')') {
            cnt--;
            return solve(s, idx + 1, cnt);
        }

        else {

            return dp[idx][cnt] = solve(s, idx + 1, cnt) ||
                                  solve(s, idx + 1, cnt + 1) ||
                                  solve(s, idx + 1, cnt - 1);
        }
    }
    bool checkValidString(string s) {

        n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, 0);
    }
};