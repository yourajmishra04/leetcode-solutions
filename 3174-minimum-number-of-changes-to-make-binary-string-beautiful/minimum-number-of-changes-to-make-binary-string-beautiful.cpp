class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int lo=0, lz=0, ro=0, rz=0;
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]!=s[i+1]) ans++;
            i+=2;
        }
        return ans;
    }
};