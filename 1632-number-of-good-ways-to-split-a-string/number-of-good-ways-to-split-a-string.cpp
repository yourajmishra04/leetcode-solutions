class Solution {
public:
    int numSplits(string s) {
      map<char,int>mpl;
      map<char,int>mpr;
      int n=s.size(), ans=0;
     
      for(int i=0;i<n;i++)mpr[s[i]]++;
      for(int i=1;i<n;i++){
        mpl[s[i-1]]++;
        mpr[s[i-1]]--;
        if(mpr[s[i-1]]==0) mpr.erase(s[i-1]);

        if(mpl.size()==mpr.size()) ans++;

      }
           return ans;


    }
};