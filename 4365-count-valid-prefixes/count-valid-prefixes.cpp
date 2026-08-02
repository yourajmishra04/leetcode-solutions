class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        vector<int> z(n, 0), o(n, 0);
        if (s[0] == '0')
            z[0] = 1;
        if (s[0] == '1')
            o[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                z[i] = z[i - 1] + 1;
                o[i] = o[i - 1];
            } else {
                o[i] = o[i - 1] + 1;
                z[i] = z[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (abs(z[i] - o[i]) < 2)
                ans++;
        }
        return ans;
    }
};