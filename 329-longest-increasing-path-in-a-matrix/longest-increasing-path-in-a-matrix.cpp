class Solution {
public:
     int ans=0;
     vector<vector<int>>dp;
     int solve(vector<vector<int>>& mat , int i, int j , long long prev){
        int n=mat.size(), m=mat[0].size();
         if(i>=n || j>=m || i<0 ||j<0 || mat[i][j] <= prev ) return 0;

         if(dp[i][j]!=-1) return dp[i][j];

         int temp= 0;
         temp= max(temp ,1 + solve(mat , i+1 , j , mat[i][j]));
         temp= max(temp ,1 + solve(mat , i-1 , j , mat[i][j]));
         temp= max(temp ,1 + solve(mat , i , j+1,  mat[i][j]));
         temp= max(temp ,1 + solve(mat , i , j -1 , mat[i][j]));
       
        return dp[i][j]= max(dp[i][j] , temp);

     }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int n=matrix.size(), m=matrix[0].size();
        dp.assign(n,vector<int>(m , -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1) solve(matrix , i,j,INT_MIN);
            }
        }

          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              ans=max(ans,dp[i][j]);
            }
        }
        return ans;

    }
};