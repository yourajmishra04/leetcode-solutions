class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
         vector<vector<int>>ans;
         int n=s1.size(), m=s2.size();
         int i=0,j=0;
         while(i<n && j<m){
            if(s1[i][0]<s2[j][0]){
                  ans.push_back({s1[i][0] , s1[i][1]+s2[j][1]});
                  i++;
            }
            else if(s1[i][0]>s2[j][0]){
                     ans.push_back({s2[j][0] , s2[j][1]+s1[i][1]});
                  j++;
            }
            else{
                  ans.push_back({s2[j][0] , s2[j][1]+s1[i][1]});
                  j++;
                  i++;

            }
         }
         while(i<n){
            ans.push_back(s1[i]);
            i++;
         }
          while(j<m){
            ans.push_back(s2[j]);
            j++;
         }
         return ans;
    }
};