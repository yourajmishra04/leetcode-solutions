class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
  
        int j = 0;
        string rev = s;
        reverse(rev.begin(), rev.end());

        string ss = s + "#" + rev;
              vector<int> lps(ss.size(), 0);

        for (int i = 1; i < ss.size(); i++) {

            while (j > 0 && ss[i] != ss[j]) {
                j = lps[j - 1];
            }

            if (ss[i] == ss[j]) {
                j++;
            }

            lps[i] = j;
        }
        string ans = "";
        int pal = 0;
       pal = lps.back();
        if (pal > 0) {
            ans += s.substr(pal , n - pal+1 );
            reverse(ans.begin(), ans.end());
        }
        ans += s;
        return ans;

        return ans;
    }
};