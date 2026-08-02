class Solution {
public:
int ans;
   void solve(vector<int>& v , int k ,int idx ){
      int n=v.size();
       

       if( v[idx]!=-1   ||  (k % (idx + 1) != 0 && (idx + 1) % k != 0)) return;

       v[idx]=k;
  if(k==n) {
        ans++;
       
       }
       else
      for(int i=0;i<n;i++) solve(v,k+1 , i);

      v[idx]=-1;


   }
    int countArrangement(int n) {
         ans=0;
        vector<int>v(n,-1);
        for(int i=0;i<n;i++)
        solve(v,1,i);
      return ans;
    }
};