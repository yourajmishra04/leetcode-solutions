class Solution {
public:
    string breakPalindrome(string p) {
        int n=p.size();
        if(n==1) return "";
            bool flg =0;
        for(int i=0;i<n;i++){
            if(p[i]!='a' && (n%2 == 0 || i != n/2)) {
                p[i]='a';
                flg=1;
                break;
            }
        }
        if(flg==1) return p;
         p[n-1]='b';
         return p;
    }
};