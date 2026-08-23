class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int tot=0;
            for(int it : matrix[i]) tot+=it;
            ans[i]=tot;
        }
        return ans;
    }
};