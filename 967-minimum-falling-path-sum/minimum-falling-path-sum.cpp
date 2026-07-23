class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
           for(int i=1;i<n;i++){
              for(int j=0;j<n;j++){
                int k=mat[i-1][j];
                if(j+1<n) k=min(k,mat[i-1][j+1]);
                if(j-1>=0)k=min(k,mat[i-1][j-1]);

                mat[i][j]+=k;
              }
           }

           int ans=INT_MAX;
           for(int i=0;i<n;i++) ans=min(ans,mat[n-1][i]);
           return ans;
    }
};