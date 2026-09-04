class Solution {
public:

  int tot;
  int n;
  vector<int>p;
  vector<int>nn;

   map<vector<int>, int> dp;
   void solve ( vector<vector<int>>& special, vector<int> curr , int ccost ) {

        if(dp.count(curr) && dp[curr] <= ccost)
            return;

    dp[curr]=ccost;


   if(nn == curr) {
    tot=min(tot, ccost);
   }
     int temp=ccost;

     for(int i=0;i<n;i++) temp+= ((nn[i]-curr[i]) * p[i]);
     tot=min(tot,temp);

      for(int i=0;i<special.size();i++){
        vector<int>nxt=curr;
        bool flg=0;
        for(int j=0;j<n;j++){
            if(nxt[j]+special[i][j] > nn[j]) {
                flg=1;
                break;
            }
            nxt[j]+=special[i][j];
        }
        if(flg==1) continue;

        solve(special  , nxt , ccost+special[i][n]);
      }
      


   }



    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        tot=0;
        dp.clear();
           n=price.size();
           for(int i=0;i<n;i++){
            tot+=(price[i] * needs[i]);
           }
           p=price;
           nn=needs;
      vector<int> curr(n,0);

       solve(special , curr,0);
       return tot;
        
    }
};