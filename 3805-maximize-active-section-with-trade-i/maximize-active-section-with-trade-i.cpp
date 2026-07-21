class Solution {
public:
int ans,l,r;
vector<int>v;

  void solve1(){
   int n=v.size();
            for(int i=2;i<n-1;i+=2){
                int temp=v[i-1];
                if((i+1)<n) temp+=v[i+1];
               
                 ans= max(ans,temp);

            }
  }
  void solve0(){
    int n=v.size();
     for(int i=1;i<n-1;i+=2){
           int temp=v[i-1];
          
           if((i+1) < n ) temp+=v[i+1];
             ans=max(ans,temp);
     }
                
  }
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
            ans=0;
            v.clear();
            int i=0, j;
            while(i<n){
                j=i;
                while(j<n && s[j]==s[i]) j++;
                v.push_back(j-i);
                i=j;

            }
            int fans=0;
             for(auto x : s) if(x== '1') fans++;
            if(s[0]=='1') solve1();
            else solve0();
            return ans + fans;
    }
};