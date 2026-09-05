class Solution {
public:
     vector<vector<int>>dp;
   int solve(vector<int>& nums , int idx , int prev){
           if(idx >= nums.size()) {
           
            return 0;
           }
           int pre=-1;
           if(prev !=INT_MIN) pre = prev +10000;
           if(pre >=0 && dp[idx][pre]!=-1) return dp[idx][pre];
               int ans = solve(nums ,idx+1 , prev);
               if(nums[idx]>prev) ans = max(ans , 1+ solve(nums , idx+1 , nums[idx]));
         if(pre>=0)  dp[idx][pre]= ans;
               return  ans;
         
     }
  
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(20001,-1));
        return solve (nums ,0, INT_MIN);
    }
};