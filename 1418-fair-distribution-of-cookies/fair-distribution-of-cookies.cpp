class Solution {
public:
int ans;
   void solve( vector<int>& v , vector<int>& c, int idx){
              
              int n=c.size();
              if(idx==n){
                int temp=0;
                for(int x : v) temp=max(temp,x);
                ans=min(ans,temp);
                return;
              }

              for(int i=0;i<v.size();i++){
                v[i]+=c[idx];
                solve(v,c,idx+1);
                v[i]-=c[idx];
              }
   }


    int distributeCookies(vector<int>& cookies, int k) {
        ans=INT_MAX;
        vector<int>v(k,0);
        solve(v,cookies , 0);
        return ans;

    }
};