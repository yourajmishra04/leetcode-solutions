class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]-=1;

        sort(nums.rbegin(),nums.rend());
        return nums[0]*nums[1];
    }
};