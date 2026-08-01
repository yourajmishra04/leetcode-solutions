class Solution {
public:
    long long minInitialStrength(vector<int>& mo, vector<vector<int>>& bo) {
        int n=mo.size();
      vector<long long> diff(n+1,0);
      for(auto it : bo){
         int l=it[0], r=it[1] , v=it[2];
           diff[l]+=v;
           if(r+1<n) diff[r+1]-=v;

      }
      long long bonus =0, ans= 0 , pre=0;
      for(int i=0;i<n;i++){
        bonus+=diff[i];

        if(bonus < mo[i]){
            long long req= pre + mo[i]- bonus;

            ans=max(ans,req); 
        }

         pre+=mo[i];
      } 
      return ans;
    }
};