class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size() , m=w2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1]){
                    v[i][j]=1+v[i-1][j-1];
                }
                else{
                    v[i][j]=max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        int mm= v[n][m];
        int ans=n-mm+m-mm;
        return ans;
    }
};