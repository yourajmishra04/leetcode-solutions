class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tot=0;
        for(int xd : nums) tot+=xd;
        int tar = tot-x;
      int ans=-1;
        int left =0, sum=0;
        for(int r=0;r<n;r++){
           sum+=nums[r];
           while(sum> tar && left <= r) {
            sum-=nums[left];
            left ++;
           }

           if(sum== tar) {
            ans=max(ans , r-left+1);
           }
        }
        if(ans== -1) return -1;
        return n-ans;
    }
};