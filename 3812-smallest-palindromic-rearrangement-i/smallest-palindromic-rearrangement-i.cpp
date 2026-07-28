class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        int n=s.size();
        string ans=s;
        char ch='1';
        int i=0, j=0;
        while(i<n-1){
            if(s[i]!=s[i+1]) ch=s[i];
            else{
                  ans[j]=s[i];
                  ans[n-j-1] = s[i+1];
                  i++;
                  j++;
            }
            i++;
        }

        if(i==n-1) ch=s[n-1];

        if(ch!='1') ans[n/2]=ch;
        return ans;


    }
};