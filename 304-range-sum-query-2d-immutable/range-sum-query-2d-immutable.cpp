class NumMatrix {
public:
vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        v=mat;
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans=0;
        for(int i=r1;i<=r2;i++){
                 
                 int n=0;
                 n+=v[i][c2];
                 if(c1>0) n-=v[i][c1-1];
                 ans+=n;
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */