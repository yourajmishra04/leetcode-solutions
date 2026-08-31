class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans= 0, n=nums.size();
         for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                ans++;
                if(nums[i+1]==1) nums[i+1]=0;
                else nums[i+1]=1;
                  if(nums[i+2]==1) nums[i+2]=0;
                else nums[i+2]=1;
            }
         }
         if(nums[n-1]==0 || nums[n-2]==0) return -1;
         return ans;

    }
};