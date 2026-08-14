class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size() , ans=0;
        map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
        
    }
};