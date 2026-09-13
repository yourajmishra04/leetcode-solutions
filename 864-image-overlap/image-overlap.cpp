class Solution {
public:
  set<pair<int,int>>st1,st2;
  int n;

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        st1.clear();
        st2.clear();
        n= img1.size();
        int t=n-1;
        int ans=0;
        for(int r=-t ; r<=t;r++){
            for(int c=-t;c<=t;c++){
                int temp=0;
                     for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                int ii=i+r;
                                int jj=j+c;
                                if(jj<0 || jj>=n || ii>=n || ii<0) continue;
                                if(img1[ii][jj]  ==1 && img2[i][j]==1) temp++;
                        }
                     }
                     ans= max(ans, temp);
            }
        }
        return ans;
    }
};