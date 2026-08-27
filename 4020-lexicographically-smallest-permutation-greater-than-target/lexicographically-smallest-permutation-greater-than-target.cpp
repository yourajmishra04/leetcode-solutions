class Solution {
public:
    string mini;
    void solve(int i, string ans, vector<int> count, string& tar) {
        int n = tar.size();
        if (i == n) {
            if (ans > tar)
                mini = min(mini, ans);
            return;
        }
        if (count[tar[i] - 'a'] > 0) {
            count[tar[i] - 'a']--;
            solve(i + 1, ans + tar[i], count, tar);
            count[tar[i] - 'a']++;
        }
        for (int j = tar[i] - 'a' + 1; j < 26; j++) {
            if (count[j] > 0) {
                ans += 'a' + j;
                count[j]--;
                for (int k = 0; k < 26; k++) {
                    while (count[k] > 0) {
                        ans += 'a' + k;
                        count[k]--;
                    }
                }
                mini = min(mini, ans);
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {

        sort(s.rbegin(), s.rend());
        if (s <= target)
            return "";
            mini=s;
        vector<int> count(27, 0);
        for (auto x : s)
            count[x - 'a']++;
        solve(0, "", count, target);
        return mini;
    }
};