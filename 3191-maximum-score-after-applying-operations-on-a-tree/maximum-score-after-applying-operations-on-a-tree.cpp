class Solution {
public:
  vector< long long>val;
   long long f( vector<vector< long long>>& mat, int node ,int par){
             
              long long ans= 0 ;

             for(auto child : mat[node]) {
                if(child != par) ans+= f(mat , child , node);
             }
               if(ans ==0) return val[node];
             return min(val[node] , ans);

   }
   

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector< int >& values) {
        int n=edges.size();
        vector<vector< long long>>mat(n+1);
        for(auto it : edges) {
            mat[it[0]].push_back(it[1]);
            mat[it[1]].push_back(it[0]);
        }
           val.clear();
           for(int i=0;i<values.size();i++) val.push_back(values[i]);
           long long mn= f(mat,0,-1);

         long long ans=0;

         for(auto x : val) ans+=x;
         ans-=mn;
         return ans;

    }
};