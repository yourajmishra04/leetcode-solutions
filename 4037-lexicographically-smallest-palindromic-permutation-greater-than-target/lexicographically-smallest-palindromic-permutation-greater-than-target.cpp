class Solution {
public:
   string mini = "";
    char mid = '\0';

    bool pal(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return 0;
            l++;
            r--;
        }
        return 1;
    }

    string makePalindrome(string half) {
        string full = half;
        if (mid != '\0') full += mid;
        string rev = half;
        reverse(rev.begin(), rev.end());
        full += rev;
        return full;
    }

    void solve(vector<int>& v, string ans, int idx, string& tar) {
        int half_len = tar.size() / 2;

        if (idx == half_len) {
            string candidate = makePalindrome(ans);
            if (candidate > tar && pal(candidate)) {
                if (mini == "" || candidate < mini)
                    mini = candidate;
            }
            return;
        }

       
        if (v[tar[idx] - 'a'] > 0) {
            v[tar[idx] - 'a']--;
            solve(v, ans + tar[idx], idx + 1, tar);
            v[tar[idx] - 'a']++;
        }

         for (int j = tar[idx] - 'a' + 1; j < 26; j++) {
            if (v[j] > 0) {
                vector<int> vv = v;
                vv[j]--;
           string half = ans + (char)('a' + j);
                for (int k = 0; k < 26; k++) {
                    while (vv[k] > 0) {
                        half += (char)('a' + k);
                        vv[k]--;
                    }
                }

                string candidate = makePalindrome(half);
                if (candidate > tar && pal(candidate)) {
                    if (mini == "" || candidate < mini) {
                        mini = candidate;
                    }
                }
                break; 
            }
        }
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> v(26, 0);
        for (char x : s) {
            v[x - 'a']++;
        }

        int odd_count = 0;
        mid = '\0';
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) {
                odd_count++;
                mid = 'a' + i;
            }
            v[i] /= 2; 
        }

        if (odd_count > 1) return "";

        mini = "";
        solve(v, "", 0, target);

        return mini;
    }
};