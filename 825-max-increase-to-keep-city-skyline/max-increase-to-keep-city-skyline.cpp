class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),fans=0;
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int mr=0, mc=0;
                for(int k=0;k<n;k++) mr=max(mr, grid[k][j]);
                for(int k=0;k<n;k++) mc=max(mc, grid[i][k]);
                if(grid[i][j]==mc || grid[i][j]==mr) continue;

                int temp=min(mc,mr);
                fans+=temp-grid[i][j];
            }
        }
        return fans;
    }
};