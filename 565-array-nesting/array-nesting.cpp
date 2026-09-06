class Solution {
public:
int f;
     void solve(vector<int>& nums , int node , vector<bool>& vis , int temp){
        if(vis[node]) {
            f=max(f , temp);
            return;
        }
        vis[node]=1;
        temp++;
        solve(nums , nums[node] , vis , temp);
     }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>mat(n);
        vector<bool>vis(n,0);
          int ans;
          f=0;
          for(int i=0;i<n;i++){
            ans=0;
            if(!vis[i]) solve(nums , i , vis, ans);
          }
          return f;
    }
};