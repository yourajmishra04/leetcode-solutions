class Solution {
public: 
    string ans;
      void con(int n){
        string s;

        for (int i = 7; i >= 0; i--) {
            if (n & (1 << i))
                s.push_back('1');
            else
                s.push_back('0');
        }

        ans += s;
      }
    bool isPalindromic(string s) {
        ans.clear();
        for(char x : s) {
            con(x);
        }
        int n= ans.size();
        int l=0, r=n-1;
        while(l<r){
            if(ans[l]!=ans[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
};