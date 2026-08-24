class Solution {
public:
 long long ans;
   int n,m;
     vector<vector<bool>>vis;
     void solve(vector<vector<int>>& grid , int i ,int j){
    if(i<0 ||j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]==0) return ;
       
       ans+=grid[i][j];
       vis[i][j]=1;
       solve(grid , i+1 , j);
       solve(grid , i-1 , j);
       solve(grid , i , j+1);
       solve(grid , i, j-1);
     }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int fans=0 ;
        vis.assign(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    ans=0;
                    solve(grid,i,j);
                    if(ans%k==0) fans++;
                }
            }
        }
        return fans;
    }
};