class Solution {
public:
int ans;
  void solve(vector<int>& nums, int target, int k ,int curr) {
    if(k>=nums.size()){
           if(curr==target) ans++;
           return;
    }

    int n=nums[k];
      
        solve(nums, target , k+1 , curr + n);
        solve(nums, target , k+1 , curr - n);


  }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans=0;
          solve(nums, target , 0 , 0);
          return ans;
    }
};