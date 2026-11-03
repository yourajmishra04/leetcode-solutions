class Solution {
public:
    int minMoves(vector<int>& nums) {
      int  n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int ans=0 , mx= nums[0];
        for (int i=0;i<n;i++) ans+=mx-nums[i];
        return ans;
    }
};