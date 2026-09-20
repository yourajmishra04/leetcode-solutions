class Solution {
public:
    int reverseDegree(string s) {
        int ans=0 , n= s.size();
        for(int i=0;i<n;i++){
            int ch= 26 - (s[i]-'a');
            ans+=(ch*(i+1));
        }
        return ans;
    }
};