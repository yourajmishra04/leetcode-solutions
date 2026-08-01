class Solution {
public:
 vector<vector<int>>ans;

 void solve(vector<int>& path , int n ,int k , int curr){
          
          if(path.size()==k){
            ans.push_back(path);
            return;
          }

          for(int i=curr;i<=n ;i++){
            path.push_back(i);
             solve(path , n,k , i+1);
             path.pop_back();
          }

 }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int>path;
        solve(path , n,k , 1);
return ans;    }
};