class Solution {
public:
    bool checkString(string s) {
        int n=s.size(),i=0;
        while(i<n && s[i]=='a') i++;
         while(i<n && s[i]=='b')i++;
         if(i<n) return 0;
         return 1;
    }
};